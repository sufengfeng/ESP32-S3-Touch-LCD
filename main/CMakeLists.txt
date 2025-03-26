
file(GLOB_RECURSE srcs *.c
                    ui/custom/*.c
                    ui/generated/*.c
                    ui/generated/guider_customer_fonts/*.c
                    ui/generated/guider_fonts/*.c
                    ui/generated/images/*.c
                    )
 
set(include_dirs 
    . 
    ui/custom 
    ui/generated 
    ui/generated/guider_customer_fonts
    ui/generated/guider_fonts
    ui/generated/images
    )
 
idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
    )

# idf_component_register(
#     SRCS "waveshare_rgb_lcd_port.c" "main.c" "lvgl_port.c"
#     INCLUDE_DIRS ".")

idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
