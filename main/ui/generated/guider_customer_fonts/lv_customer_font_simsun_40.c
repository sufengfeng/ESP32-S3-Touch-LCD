/*******************************************************************************
 * Size: 40 px
 * Bpp: 4
 * Opts: undefined
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef LV_CUSTOMER_FONT_SIMSUN_40
#define LV_CUSTOMER_FONT_SIMSUN_40 1
#endif

#if LV_CUSTOMER_FONT_SIMSUN_40

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0x12, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x21, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf9, 0x35, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x52,

    /* U+0030 "0" */
    0x0, 0x0, 0x0, 0x6c, 0xee, 0xc6, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xdf, 0xc6, 0x5b, 0xfc, 0x10,
    0x0, 0x0, 0x1, 0xef, 0xa0, 0x0, 0x7, 0xfd,
    0x0, 0x0, 0x0, 0xbf, 0xe0, 0x0, 0x0, 0xc,
    0xfa, 0x0, 0x0, 0x4f, 0xf6, 0x0, 0x0, 0x0,
    0x4f, 0xf3, 0x0, 0xb, 0xff, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xa0, 0x1, 0xff, 0xa0, 0x0, 0x0,
    0x0, 0xb, 0xff, 0x0, 0x6f, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xf4, 0xa, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x5, 0xff, 0x80, 0xcf, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xfa, 0xf, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xd0, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xfd, 0x1f, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xe1, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0x1f,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xe0,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xfd,
    0xf, 0xff, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xc0, 0xdf, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xfa, 0xa, 0xff, 0x30, 0x0, 0x0, 0x0, 0x5,
    0xff, 0x70, 0x6f, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xf4, 0x2, 0xff, 0xa0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0x0, 0xc, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x90, 0x0, 0x4f, 0xf5, 0x0, 0x0,
    0x0, 0x5f, 0xf2, 0x0, 0x0, 0xbf, 0xd0, 0x0,
    0x0, 0xd, 0xf9, 0x0, 0x0, 0x1, 0xdf, 0xa0,
    0x0, 0x8, 0xfd, 0x0, 0x0, 0x0, 0x1, 0xcf,
    0xc5, 0x5b, 0xfc, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x6c, 0xee, 0xc6, 0x0, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1e, 0x7f, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xab, 0x2f, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xf2, 0x2f, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0x70, 0x2f, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x8c, 0x0, 0x2f, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xf3, 0x0, 0x2f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0xc, 0x80, 0x0, 0x2f,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x6e, 0x0, 0x0,
    0x2f, 0xf6, 0x0, 0x0, 0x0, 0x1, 0xe4, 0x0,
    0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0, 0xa, 0xa0,
    0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0, 0x4e,
    0x10, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0,
    0xe6, 0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0,
    0x8, 0xc0, 0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0,
    0x0, 0x3f, 0x20, 0x0, 0x0, 0x0, 0x2f, 0xf6,
    0x0, 0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xaf, 0xfd,
    0x30, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xff, 0xff, 0xf1,

    /* U+0069 "i" */
    0x0, 0x0, 0x3d, 0xe6, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0x10, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0x10, 0x0, 0x0, 0x0, 0x2d, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0x37, 0xd1, 0x0, 0x0, 0xbf, 0xff,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x5f, 0xf6, 0x0, 0x0, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xfc,

    /* U+006D "m" */
    0x0, 0x15, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0xff, 0x32, 0xae, 0xfb, 0x20,
    0x2a, 0xef, 0xb2, 0x0, 0x16, 0xff, 0x6e, 0x85,
    0xbf, 0xd3, 0xe8, 0x5a, 0xfb, 0x0, 0x0, 0xff,
    0xe3, 0x0, 0x1f, 0xfe, 0x40, 0x1, 0xff, 0x10,
    0x0, 0xff, 0x90, 0x0, 0xf, 0xf9, 0x0, 0x0,
    0xef, 0x30, 0x0, 0xff, 0x40, 0x0, 0xf, 0xf4,
    0x0, 0x0, 0xef, 0x40, 0x0, 0xff, 0x30, 0x0,
    0xf, 0xf4, 0x0, 0x0, 0xef, 0x40, 0x0, 0xff,
    0x30, 0x0, 0xf, 0xf4, 0x0, 0x0, 0xef, 0x40,
    0x0, 0xff, 0x30, 0x0, 0xf, 0xf4, 0x0, 0x0,
    0xef, 0x40, 0x0, 0xff, 0x30, 0x0, 0xf, 0xf4,
    0x0, 0x0, 0xef, 0x40, 0x0, 0xff, 0x30, 0x0,
    0xf, 0xf4, 0x0, 0x0, 0xef, 0x40, 0x0, 0xff,
    0x30, 0x0, 0xf, 0xf4, 0x0, 0x0, 0xef, 0x40,
    0x0, 0xff, 0x30, 0x0, 0xf, 0xf4, 0x0, 0x0,
    0xef, 0x40, 0x0, 0xff, 0x30, 0x0, 0xf, 0xf4,
    0x0, 0x0, 0xef, 0x40, 0x0, 0xff, 0x30, 0x0,
    0xf, 0xf4, 0x0, 0x0, 0xef, 0x40, 0x0, 0xff,
    0x30, 0x0, 0xf, 0xf4, 0x0, 0x0, 0xef, 0x40,
    0x0, 0xff, 0x30, 0x0, 0xf, 0xf4, 0x0, 0x0,
    0xef, 0x40, 0x2, 0xff, 0x60, 0x0, 0x2f, 0xf7,
    0x0, 0x2, 0xff, 0x70, 0x8f, 0xff, 0xfc, 0x7,
    0xff, 0xff, 0xc0, 0x7f, 0xff, 0xfd,

    /* U+006E "n" */
    0x0, 0x27, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x9f, 0xff, 0xa0, 0x3, 0xae, 0xfe, 0xa3,
    0x0, 0x0, 0x24, 0xcf, 0xa0, 0x8f, 0xa6, 0x48,
    0xff, 0x50, 0x0, 0x0, 0x9f, 0xaa, 0xd3, 0x0,
    0x0, 0x5f, 0xe0, 0x0, 0x0, 0x9f, 0xfc, 0x10,
    0x0, 0x0, 0xd, 0xf4, 0x0, 0x0, 0x9f, 0xe1,
    0x0, 0x0, 0x0, 0xb, 0xf7, 0x0, 0x0, 0x9f,
    0xa0, 0x0, 0x0, 0x0, 0xa, 0xf8, 0x0, 0x0,
    0x9f, 0xa0, 0x0, 0x0, 0x0, 0xa, 0xf9, 0x0,
    0x0, 0x9f, 0xa0, 0x0, 0x0, 0x0, 0xa, 0xf9,
    0x0, 0x0, 0x9f, 0xa0, 0x0, 0x0, 0x0, 0xa,
    0xf9, 0x0, 0x0, 0x9f, 0xa0, 0x0, 0x0, 0x0,
    0xa, 0xf9, 0x0, 0x0, 0x9f, 0xa0, 0x0, 0x0,
    0x0, 0xa, 0xf9, 0x0, 0x0, 0x9f, 0xa0, 0x0,
    0x0, 0x0, 0xa, 0xf9, 0x0, 0x0, 0x9f, 0xa0,
    0x0, 0x0, 0x0, 0xa, 0xf9, 0x0, 0x0, 0x9f,
    0xa0, 0x0, 0x0, 0x0, 0xa, 0xf9, 0x0, 0x0,
    0x9f, 0xa0, 0x0, 0x0, 0x0, 0xa, 0xf9, 0x0,
    0x0, 0x9f, 0xa0, 0x0, 0x0, 0x0, 0xa, 0xf9,
    0x0, 0x0, 0xcf, 0xd1, 0x0, 0x0, 0x0, 0x1d,
    0xfc, 0x10, 0xbf, 0xff, 0xff, 0xc0, 0x0, 0xc,
    0xff, 0xff, 0xfb,

    /* U+0073 "s" */
    0x0, 0x3, 0x9d, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0x8, 0xf8, 0x20, 0x2, 0x8f, 0xff, 0x10, 0x7,
    0xf3, 0x0, 0x0, 0x0, 0x3f, 0xf3, 0x0, 0xed,
    0x0, 0x0, 0x0, 0x0, 0x4f, 0x50, 0xf, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0xc7, 0x0, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x2, 0x10, 0xa, 0xfe, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0xff, 0xf9,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x6, 0xdf, 0xff,
    0xe8, 0x20, 0x0, 0x0, 0x0, 0x0, 0x3a, 0xff,
    0xff, 0xa1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c,
    0xff, 0xd1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xef, 0x90, 0x95, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfe, 0x9, 0xa0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0xf0, 0x8f, 0x20, 0x0, 0x0, 0x0, 0x0, 0xec,
    0x7, 0xfd, 0x10, 0x0, 0x0, 0x0, 0x5f, 0x50,
    0x5f, 0xff, 0x83, 0x0, 0x2, 0x8f, 0x80, 0x4,
    0xa4, 0x49, 0xdf, 0xff, 0xd9, 0x30, 0x0,

    /* U+0075 "u" */
    0x0, 0x2, 0x97, 0x0, 0x0, 0x0, 0x1, 0x39,
    0x60, 0x0, 0xff, 0xff, 0x70, 0x0, 0x0, 0x1f,
    0xff, 0xf6, 0x0, 0x0, 0x1e, 0xf7, 0x0, 0x0,
    0x0, 0x2, 0xff, 0x60, 0x0, 0x0, 0xbf, 0x70,
    0x0, 0x0, 0x0, 0xc, 0xf6, 0x0, 0x0, 0xb,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x60, 0x0,
    0x0, 0xbf, 0x70, 0x0, 0x0, 0x0, 0xc, 0xf6,
    0x0, 0x0, 0xb, 0xf7, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0x60, 0x0, 0x0, 0xbf, 0x70, 0x0, 0x0,
    0x0, 0xc, 0xf6, 0x0, 0x0, 0xb, 0xf7, 0x0,
    0x0, 0x0, 0x0, 0xcf, 0x60, 0x0, 0x0, 0xbf,
    0x70, 0x0, 0x0, 0x0, 0xc, 0xf6, 0x0, 0x0,
    0xb, 0xf7, 0x0, 0x0, 0x0, 0x0, 0xcf, 0x60,
    0x0, 0x0, 0xbf, 0x70, 0x0, 0x0, 0x0, 0xc,
    0xf6, 0x0, 0x0, 0xb, 0xf7, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0x60, 0x0, 0x0, 0xbf, 0x70, 0x0,
    0x0, 0x0, 0xd, 0xf6, 0x0, 0x0, 0x9, 0xf9,
    0x0, 0x0, 0x0, 0x3, 0xff, 0x60, 0x0, 0x0,
    0x6f, 0xd0, 0x0, 0x0, 0x0, 0xcf, 0xf6, 0x0,
    0x0, 0x1, 0xff, 0x80, 0x0, 0x2, 0xb9, 0xcf,
    0xb0, 0x0, 0x0, 0x7, 0xff, 0xeb, 0xac, 0xfa,
    0xc, 0xff, 0xfb, 0x0, 0x0, 0x5, 0xcf, 0xfd,
    0xa4, 0x0, 0xb9, 0x30, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 320, .box_w = 18, .box_h = 3, .ofs_x = 1, .ofs_y = 14},
    {.bitmap_index = 27, .adv_w = 320, .box_w = 17, .box_h = 27, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 257, .adv_w = 320, .box_w = 18, .box_h = 27, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 500, .adv_w = 320, .box_w = 12, .box_h = 27, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 662, .adv_w = 320, .box_w = 20, .box_h = 19, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 852, .adv_w = 320, .box_w = 18, .box_h = 19, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1023, .adv_w = 320, .box_w = 15, .box_h = 18, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 1158, .adv_w = 320, .box_w = 19, .box_h = 19, .ofs_x = 0, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x3, 0x7, 0x3c, 0x40, 0x41, 0x46, 0x48
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 73, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t lv_customer_font_simsun_40 = {
#else
lv_font_t lv_customer_font_simsun_40 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 27,          /*The maximum line height required by the font*/
    .base_line = -1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if LV_CUSTOMER_FONT_SIMSUN_40*/

