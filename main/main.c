/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#if 0

#include "waveshare_rgb_lcd_port.h"

void app_main()
{
    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 
    // wavesahre_rgb_lcd_bl_on();  //Turn on the screen backlight 
    // wavesahre_rgb_lcd_bl_off(); //Turn off the screen backlight 
    
    ESP_LOGI(TAG, "Display LVGL demos");
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        // lv_demo_stress();
        // lv_demo_benchmark();
        // lv_demo_music();
        lv_demo_widgets();
        // example_lvgl_demo_ui();
        // Release the mutex
        lvgl_port_unlock();
    }
}
#else


/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
#include "sdkconfig.h"
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h> // struct addrinfo
#include <arpa/inet.h>
#include "esp_netif.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/uart.h"
#include "esp_task_wdt.h"

#include "esp_event.h"
#include <stdio.h>
// #include <nvs.h>
#include "esp_crc.h"
#include <string.h> // 添加这一行
// #include "waveshare_rgb_lcd_port.h"



esp_err_t waveshare_esp32_s3_rgb_lcd_init();
bool lvgl_port_lock(int timeout_ms);
void lv_demo_widgets(void);
void lvgl_port_unlock(void);

#if defined(CONFIG_EXAMPLE_SOCKET_IP_INPUT_STDIN)
#include "addr_from_stdin.h"
#endif

// #define HOST_IP_ADDR "192.168.1.14"
#define HOST_IP_ADDR "192.168.76.204"
#define PORT 3333
#define TAG "debugsufeng"
// #define WIFI_SSID "your_wifi_ssid"
// #define WIFI_PASSWORD "your_wifi_password"
#define WIFI_SSID "CMCC-V5m3"
#define WIFI_PASSWORD "m492wsmw"
#define WIFI_AUTHMODE WIFI_AUTH_WPA2_PSK
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
#define WIFI_RETRY_ATTEMPT 3
#define UART_NUM UART_NUM_0
#define BUF_SIZE (1024)

static const char *payload = "Message from ESP32 ";
static int wifi_retry_count = 0;
static esp_netif_t *tutorial_netif = NULL;
static esp_event_handler_instance_t ip_event_handler;
static esp_event_handler_instance_t wifi_event_handler;
static EventGroupHandle_t s_wifi_event_group = NULL;

uint8_t g_nFlagIsWifiConneted = 0; // wifi网络连接标志位
// 串口接收处理任务
void uart_task(void *pvParameters)
{
    uint8_t tmpBuff[BUF_SIZE] = {0};
    while (1)
    {
        memset(tmpBuff, 0, BUF_SIZE);
        int len = uart_read_bytes(UART_NUM, tmpBuff, BUF_SIZE, 20 / portTICK_PERIOD_MS);
        if (len > 0)
        {
            ESP_LOGI(TAG, "Received %d bytes from UART: %.*s", len, len, tmpBuff);
            if (strcmp((char *)tmpBuff, "LED_ON") == 0)
            {
                ESP_LOGI(TAG, "Received LED_ON command, turning on the LED");
                // Here you can add code to control the LED
            }
            else if (strcmp((char *)tmpBuff, "reboot") == 0)
            {
                ESP_LOGI(TAG, "Received reboot command, the system will restart");
                esp_restart();
            }
            else
            {
                ESP_LOGE(TAG, "Unknown command: %s", tmpBuff);
            }
        }
        vTaskDelay(pdMS_TO_TICKS(400)); // Yield the CPU for 100 milliseconds
    }
}

// Socket 任务，使用 tcp_client 处理
void tcp_client(void)
{
    char rx_buffer[128];
    char host_ip[] = HOST_IP_ADDR;
    int addr_family = 0;
    int ip_protocol = 0;

    while (1)
    {
        while (g_nFlagIsWifiConneted == 0)
        { // 如果网络未连接，则循环等待
            vTaskDelay(pdMS_TO_TICKS(800));
        }
        struct sockaddr_in dest_addr;
        inet_pton(AF_INET, host_ip, &dest_addr.sin_addr);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;

        int sock = socket(addr_family, SOCK_STREAM, ip_protocol);
        if (sock < 0)
        {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
            vTaskDelay(pdMS_TO_TICKS(5000));
            continue;
        }
        ESP_LOGI(TAG, "Socket created, connecting to %s:%d", host_ip, PORT);

        int err = connect(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err != 0)
        {
            ESP_LOGE(TAG, "Socket unable to connect: errno %d", errno);
            close(sock);
            vTaskDelay(pdMS_TO_TICKS(5000));
            continue;
        }
        ESP_LOGI(TAG, "Successfully connected");

        while (1)
        {
            int err = send(sock, payload, strlen(payload), 0);
            if (err < 0)
            {
                ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                break;
            }

            int len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
            // Error occurred during receiving
            if (len < 0)
            {
                ESP_LOGE(TAG, "recv failed: errno %d", errno);
                break;
            }
            // Data received
            else
            {
                rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string
                ESP_LOGI(TAG, "Received %d bytes from %s:", len, host_ip);
                ESP_LOGI(TAG, "%s", rx_buffer);
            }
            if (g_nFlagIsWifiConneted == 0)
            { // 检测到wifi断开，则等待网络连接
                break;
            }
            vTaskDelay(pdMS_TO_TICKS(100)); // Yield the CPU for 100 milliseconds
        }

        if (sock != -1)
        {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock, 0);
            close(sock);
        }
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// WiFi 事件处理回调
static void wifi_event_cb(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    ESP_LOGI(TAG, "Handling Wi-Fi event, event code 0x%" PRIx32, event_id);

    switch (event_id)
    {
    case (WIFI_EVENT_WIFI_READY):
        ESP_LOGI(TAG, "Wi-Fi ready");
        break;
    case (WIFI_EVENT_SCAN_DONE):
        ESP_LOGI(TAG, "Wi-Fi scan done");
        break;
    case (WIFI_EVENT_STA_START):
        ESP_LOGI(TAG, "Wi-Fi started, connecting to AP...");
        esp_wifi_connect();
        break;
    case (WIFI_EVENT_STA_STOP):
        ESP_LOGI(TAG, "Wi-Fi stopped");
        break;
    case (WIFI_EVENT_STA_CONNECTED):
        ESP_LOGI(TAG, "Wi-Fi connected");
        g_nFlagIsWifiConneted = 1;
        break;
    case (WIFI_EVENT_STA_DISCONNECTED):
        ESP_LOGI(TAG, "Wi-Fi disconnected");
        g_nFlagIsWifiConneted = 0;
        if (wifi_retry_count < WIFI_RETRY_ATTEMPT)
        {
            ESP_LOGI(TAG, "Retrying to connect to Wi-Fi network...");
            esp_wifi_connect();
            wifi_retry_count++;
        }
        else
        {
            ESP_LOGI(TAG, "Failed to connect to Wi-Fi network");
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        break;
    case (WIFI_EVENT_STA_AUTHMODE_CHANGE):
        ESP_LOGI(TAG, "Wi-Fi authmode changed");
        break;
    default:
        ESP_LOGI(TAG, "Wi-Fi event not handled");
        break;
    }
}

// IP 事件处理回调
static void ip_event_cb(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
{
    ESP_LOGI(TAG, "Handling IP event, event code 0x%" PRIx32, event_id);
    switch (event_id)
    {
    case (IP_EVENT_STA_GOT_IP):
        ip_event_got_ip_t *event_ip = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "Got IP: " IPSTR, IP2STR(&event_ip->ip_info.ip));
        wifi_retry_count = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
        break;
    case (IP_EVENT_STA_LOST_IP):
        ESP_LOGI(TAG, "Lost IP");
        break;
    case (IP_EVENT_GOT_IP6):
        ip_event_got_ip6_t *event_ip6 = (ip_event_got_ip6_t *)event_data;
        ESP_LOGI(TAG, "Got IPv6: " IPV6STR, IPV62STR(event_ip6->ip6_info.ip));
        wifi_retry_count = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
        break;
    default:
        ESP_LOGI(TAG, "IP event not handled");
        break;
    }
}

// 初始化 WiFi
esp_err_t tutorial_init(void)
{
    s_wifi_event_group = xEventGroupCreate();
    esp_err_t ret = esp_netif_init();
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to initialize TCP/IP network stack");
        return ret;
    }

    ret = esp_event_loop_create_default();
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to create default event loop");
        return ret;
    }

    ret = esp_wifi_set_default_wifi_sta_handlers();
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to set default handlers");
        return ret;
    }

    tutorial_netif = esp_netif_create_default_wifi_sta();
    if (tutorial_netif == NULL)
    {
        ESP_LOGE(TAG, "Failed to create default WiFi STA interface");
        return ESP_FAIL;
    }

    // Wi-Fi stack configuration parameters
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_cb,
                                                        NULL,
                                                        &wifi_event_handler));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &ip_event_cb,
                                                        NULL,
                                                        &ip_event_handler));
    return ret;
}
void print_wifi_info()
{

    wifi_ap_record_t ap_info;
    esp_err_t ret = esp_wifi_sta_get_ap_info(&ap_info);
    if (ret == ESP_ERR_WIFI_CONN)
    {
        ESP_LOGE(TAG, "Wi-Fi station interface not initialized");
    }
    else if (ret == ESP_ERR_WIFI_NOT_CONNECT)
    {
        ESP_LOGE(TAG, "Wi-Fi station is not connected");
    }
    else
    {
        ESP_LOGI(TAG, "--- Access Point Information ---");
        ESP_LOG_BUFFER_HEX("MAC Address", ap_info.bssid, sizeof(ap_info.bssid));
        ESP_LOG_BUFFER_CHAR("SSID", ap_info.ssid, sizeof(ap_info.ssid));
        ESP_LOGI(TAG, "Primary Channel: %d", ap_info.primary);
        ESP_LOGI(TAG, "RSSI: %d", ap_info.rssi);

        // ESP_LOGI(TAG, "Disconnecting in 5 seconds...");
        // vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
// 连接 WiFi
esp_err_t tutorial_connect(char *wifi_ssid, char *wifi_password)
{
    // 重新创建事件组
    if (s_wifi_event_group == NULL)
    {
        s_wifi_event_group = xEventGroupCreate();
        if (s_wifi_event_group == NULL)
        {
            ESP_LOGE(TAG, "Failed to create event group");
            return ESP_FAIL;
        }
    }
    wifi_config_t wifi_config = {
        .sta = {
            // this sets the weakest authmode accepted in fast scan mode (default)
            .threshold.authmode = WIFI_AUTHMODE,
        },
    };

    strncpy((char *)wifi_config.sta.ssid, wifi_ssid, sizeof(wifi_config.sta.ssid));
    strncpy((char *)wifi_config.sta.password, wifi_password, sizeof(wifi_config.sta.password));

    ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_NONE));          // default is WIFI_PS_MIN_MODEM
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM)); // default is WIFI_STORAGE_FLASH

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

    ESP_LOGI(TAG, "Connecting to Wi-Fi network: %s", wifi_config.sta.ssid);
    ESP_ERROR_CHECK(esp_wifi_start());

    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group, WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE, pdFALSE, portMAX_DELAY);
    print_wifi_info(); // 打印 Wi-Fi 信息
    if (bits & WIFI_CONNECTED_BIT)
    {
        ESP_LOGI(TAG, "Connected to Wi-Fi network: %s", wifi_config.sta.ssid);

        return ESP_OK;
    }
    else if (bits & WIFI_FAIL_BIT)
    {
        ESP_LOGE(TAG, "Failed to connect to Wi-Fi network: %s", wifi_config.sta.ssid);
        return ESP_FAIL;
    }

    ESP_LOGE(TAG, "Unexpected Wi-Fi error");
    return ESP_FAIL;
}

// 断开 WiFi
esp_err_t tutorial_disconnect(void)
{
    if (s_wifi_event_group)
    {
        vEventGroupDelete(s_wifi_event_group);
    }

    return esp_wifi_disconnect();
}

// 反初始化 WiFi
esp_err_t tutorial_deinit(void)
{
    esp_err_t ret = esp_wifi_stop();
    if (ret == ESP_ERR_WIFI_NOT_INIT)
    {
        ESP_LOGE(TAG, "Wi-Fi stack not initialized");
        return ret;
    }

    ESP_ERROR_CHECK(esp_wifi_deinit());
    ESP_ERROR_CHECK(esp_wifi_clear_default_wifi_driver_and_handlers(tutorial_netif));
    esp_netif_destroy(tutorial_netif);

    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, ESP_EVENT_ANY_ID, ip_event_handler));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler));

    return ESP_OK;
}
#define NVS_NAMESPACE "user_config"
#define KEY_CONFIG "config_data"

// 定义配置结构体
typedef struct
{
    uint8_t m_nSymbol[4];   // 符号 CONF
    uint8_t m_nServerIp[4]; // 服务器IP地址 192.168.1.14

    uint16_t m_nServerPort; // 服务器端口号 3333
    uint16_t m_nSerialNum;  // 序列号 0x0101 1号房间，1号位

    uint32_t resvalues[8];
    uint32_t crc;
} ConfigData;
// 定义默认配置
const ConfigData default_config = {
    .m_nSymbol = {'C', 'O', 'N', 'F'},
    .m_nServerIp = {192, 168, 1, 14},
    .m_nServerPort = 3333,
    .m_nSerialNum = 0x0101,
    .resvalues = {0},
    .crc = 0 // 后续会重新计算
};

// 计算CRC校验值，只计算前11个值
uint32_t calculate_crc(const ConfigData *config, size_t length)
{
    return esp_crc32_le(0, (const uint8_t *)config, length);
}

// 写入配置数据
esp_err_t write_config(const ConfigData *config)
{
    nvs_handle_t my_handle;
    esp_err_t err = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &my_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }

    ConfigData config_with_crc = *config;
    // 计算并设置CRC校验值到第12个位置
    config_with_crc.crc = calculate_crc(config, sizeof(uint32_t) * 11);

    // 写入配置数据
    err = nvs_set_blob(my_handle, KEY_CONFIG, &config_with_crc, sizeof(ConfigData));
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) writing config data!\n", esp_err_to_name(err));
        nvs_close(my_handle);
        return err;
    }

    // 提交更改
    err = nvs_commit(my_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) committing changes!\n", esp_err_to_name(err));
    }

    // 关闭NVS句柄
    nvs_close(my_handle);
    return err;
}

// 读取配置数据
esp_err_t read_config(ConfigData *config)
{
    nvs_handle_t my_handle;
    esp_err_t err = nvs_open(NVS_NAMESPACE, NVS_READONLY, &my_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        return err;
    }

    // 读取配置数据
    size_t required_size = sizeof(ConfigData);
    err = nvs_get_blob(my_handle, KEY_CONFIG, config, &required_size);
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) reading config data!\n", esp_err_to_name(err));
        nvs_close(my_handle);
        return err;
    }

    // 计算读取数据的CRC校验值（前11个值）
    uint32_t calculated_crc = calculate_crc(config, sizeof(uint32_t) * 11);
    uint32_t stored_crc = config->crc;
    if (calculated_crc != stored_crc)
    {
        ESP_LOGE("NVS", "CRC check failed! Data may be corrupted.\n");
        err = ESP_ERR_INVALID_CRC;
    }

    // 关闭NVS句柄
    nvs_close(my_handle);
    return err;
}

#include <string.h> // 添加这一行

// 封装写入默认配置的函数
esp_err_t write_default_config()
{
    ConfigData config_to_write = default_config;
    config_to_write.crc = calculate_crc(&config_to_write, sizeof(uint32_t) * 11);
    esp_err_t err = write_config(&config_to_write);
    if (err != ESP_OK)
    {
        ESP_LOGE("NVS", "Error (%s) writing default config!\n", esp_err_to_name(err));
    }
    else
    {
        ESP_LOGI(TAG, "Default config written successfully.");
    }
    return err;
}
// 封装打印函数
void printConfigData(ConfigData read_config_data)
{
    // 打印 m_nSymbol
    ESP_LOGI(TAG, "  m_nSymbol[%s]", read_config_data.m_nSymbol);

    // 打印 m_nServerIp
    ESP_LOGI(TAG, "  m_nServerIp : %u.%u.%u.%u", read_config_data.m_nServerIp[0], read_config_data.m_nServerIp[1], read_config_data.m_nServerIp[2], read_config_data.m_nServerIp[3]);

    // 打印 m_nServerPort
    ESP_LOGI(TAG, "m_nServerPort: %u", read_config_data.m_nServerPort);

    // 打印 m_nSerialNum
    ESP_LOGI(TAG, "m_nSerialNum: %u", read_config_data.m_nSerialNum);

    // 打印 crc
    ESP_LOGI(TAG, "crc: 0x%04lx", read_config_data.crc);
}
// 定义一个 FreeRTOS 任务函数用于维护 Wi-Fi 连接
void wifi_maintenance_task(void *pvParameters)
{
    while (1)
    {
        // 检查 Wi-Fi 连接状态
        wifi_ap_record_t ap_info;
        esp_err_t err = esp_wifi_sta_get_ap_info(&ap_info);
        if (err != ESP_OK)
        {
            esp_err_t ret = ESP_OK;
            g_nFlagIsWifiConneted = 0; // 获取失败，认为网络断开
            // 根据不同的错误类型进行处理
            switch (err)
            {
            case ESP_ERR_WIFI_NOT_INIT:
                ESP_LOGE(TAG, "Wi-Fi stack not initialized");
                ESP_ERROR_CHECK(tutorial_init()); // 这里可以考虑重新初始化 Wi-Fi// 这里可以考虑重新初始化 Wi-Fi
                break;
            case ESP_ERR_WIFI_NOT_CONNECT:
                ESP_LOGE(TAG, "Wi-Fi station is not connected");
                // 断开连接并尝试重新连接
                ESP_ERROR_CHECK(tutorial_disconnect());
                ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
                ret = tutorial_connect(WIFI_SSID, WIFI_PASSWORD);
                if (ret != ESP_OK)
                {
                    ESP_LOGE(TAG, "Failed to reconnect to Wi-Fi network");
                }
                else
                {
                    ESP_LOGI(TAG, "Successfully reconnected to Wi-Fi network");
                }
                break;
            default:
                ESP_LOGE(TAG, "Unexpected Wi-Fi error: %s", esp_err_to_name(err));
                // 可以根据实际情况决定是否断开连接和重新连接
                // 这里暂时断开连接并尝试重新连接
                ESP_ERROR_CHECK(tutorial_disconnect());
                ESP_LOGI(TAG, "Wi-Fi disconnected, trying to reconnect...");
                ret = tutorial_connect(WIFI_SSID, WIFI_PASSWORD);
                if (ret != ESP_OK)
                {
                    ESP_LOGE(TAG, "Failed to reconnect to Wi-Fi network");
                }
                else
                {
                    ESP_LOGI(TAG, "Successfully reconnected to Wi-Fi network");
                }
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(5000)); // 每 5 秒检查一次连接状态
    }
}
// 主函数
void app_main()
{
    // 配置任务看门狗定时器
    esp_task_wdt_config_t config = {
        .timeout_ms = 5000,                    // 超时时间为 5 秒
        .idle_core_mask = (1 << 0) | (1 << 1), // 监控核心 0 和核心 1 的空闲任务
        .trigger_panic = true                  // 超时触发系统崩溃异常
    };

    // 初始化任务看门狗定时器
    esp_err_t err = esp_task_wdt_init(&config);
    if (err != ESP_OK)
    {
        // 处理初始化失败的情况
        ESP_LOGE("TWDT", "Failed to initialize Task Watchdog Timer, error code: %d", err);
    }

    // Initialize Non-Volatile Storage (NVS)
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    // 读取配置数据
    ConfigData read_config_data;
    err = read_config(&read_config_data);
    if (err != ESP_OK)
    {
        // 读取失败，写入默认配置
        err = write_default_config();
        if (err != ESP_OK)
        {
            return;
        }
        // 重新读取配置数据
        err = read_config(&read_config_data);
        if (err != ESP_OK)
        {
            ESP_LOGE("NVS", "Error (%s) reading config after possible write!\n", esp_err_to_name(err));
            return;
        }
    }

    // 打印读取的配置数据
    printConfigData(read_config_data);

    // 初始化 UART
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};
    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);

    // 初始化 WiFi
    ESP_ERROR_CHECK(tutorial_init());
    ESP_ERROR_CHECK(tutorial_connect((char *)WIFI_SSID, (char *)WIFI_PASSWORD));

    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 
    // wavesahre_rgb_lcd_bl_on();  //Turn on the screen backlight 
    // wavesahre_rgb_lcd_bl_off(); //Turn off the screen backlight 

    ESP_LOGI(TAG, "Display LVGL demos");
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        // lv_demo_stress();
        // lv_demo_benchmark();
        // lv_demo_music();
        lv_demo_widgets();
        // example_lvgl_demo_ui();
        // Release the mutex
        lvgl_port_unlock();
    }

    // 创建串口任务
    xTaskCreate(uart_task, "uart_task", 4096, NULL, 1, NULL);
    // 创建 Socket 任务
    xTaskCreate(tcp_client, "tcp_client_task", 8192, NULL, 1, NULL);
    // 创建Wi-Fi维护任务
    xTaskCreate(wifi_maintenance_task, "wifi_maintenance_task", 8192, NULL, 1, NULL);

    while (1)
    {
        // ESP_LOGI(TAG, "app_main is running");
        vTaskDelay(pdMS_TO_TICKS(2000)); // 让出 CPU 2000 毫秒
    }
    ESP_ERROR_CHECK(tutorial_disconnect());

    ESP_ERROR_CHECK(tutorial_deinit());

    ESP_LOGI(TAG, "End of tutorial...");
}
#endif