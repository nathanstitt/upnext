/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --font /Users/nas/SquareLine/assets/Lato-Regular.ttf -o /Users/nas/SquareLine/assets/ui_font_lato18.c --format lvgl -r 0x20-0x7f --symbols :@°&/¾½¼⛆❄\!()., --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_LATO18
#define UI_FONT_LATO18 1
#endif

#if UI_FONT_LATO18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0x3, 0xc0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x9, 0x82, 0x61, 0x90, 0x64, 0x7f, 0xc4, 0xc1,
    0x30, 0xc8, 0xff, 0x88, 0x82, 0x60, 0x98, 0x24,
    0x0,

    /* U+0024 "$" */
    0x4, 0x2, 0x7, 0x86, 0xf6, 0x43, 0x21, 0x90,
    0x78, 0x1f, 0x5, 0xc2, 0x61, 0x34, 0x9b, 0x58,
    0xf8, 0x10, 0x8, 0x0,

    /* U+0025 "%" */
    0x78, 0x37, 0x61, 0x31, 0x11, 0x89, 0x8c, 0x48,
    0x74, 0x81, 0xec, 0x0, 0xde, 0x5, 0x88, 0x4c,
    0x46, 0x62, 0x63, 0x12, 0xf, 0x0,

    /* U+0026 "&" */
    0xe, 0x1, 0x30, 0x21, 0x2, 0x0, 0x20, 0x3,
    0x0, 0x38, 0x6, 0xc4, 0xc6, 0x4c, 0x3c, 0xc1,
    0x86, 0x3c, 0x3e, 0x60,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x3, 0x26, 0x6c, 0xcc, 0xcc, 0xcc, 0x66, 0x23,
    0x0,

    /* U+0029 ")" */
    0xc, 0x46, 0x63, 0x33, 0x33, 0x33, 0x66, 0x4c,
    0x0,

    /* U+002A "*" */
    0x25, 0x5d, 0xf2, 0x0,

    /* U+002B "+" */
    0x18, 0xc, 0x6, 0x1f, 0xf1, 0x80, 0xc0, 0x60,
    0x30,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x6, 0x8, 0x30, 0x40, 0x83, 0x4, 0x18, 0x20,
    0x41, 0x2, 0xc, 0x10, 0x0,

    /* U+0030 "0" */
    0x1e, 0xc, 0xc6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x36, 0x19, 0xcc, 0x1e,
    0x0,

    /* U+0031 "1" */
    0xc, 0x1c, 0x7c, 0xcc, 0xc, 0xc, 0xc, 0xc,
    0xc, 0xc, 0xc, 0xc, 0x7f,

    /* U+0032 "2" */
    0x1e, 0x31, 0x90, 0x68, 0x30, 0x18, 0x1c, 0xc,
    0xc, 0xc, 0xc, 0xc, 0xc, 0xf, 0xf8,

    /* U+0033 "3" */
    0x1e, 0x11, 0x90, 0x68, 0x30, 0x18, 0x18, 0x38,
    0x6, 0x1, 0x80, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0034 "4" */
    0x3, 0x1, 0xc0, 0xf0, 0x6c, 0x13, 0xc, 0xc6,
    0x31, 0xc, 0xc3, 0x3f, 0xf0, 0x30, 0xc, 0x3,
    0x0,

    /* U+0035 "5" */
    0x3f, 0x10, 0x8, 0xc, 0x6, 0x3, 0xf0, 0xc,
    0x3, 0x1, 0x80, 0xc0, 0x68, 0x67, 0xe0,

    /* U+0036 "6" */
    0x6, 0x6, 0x6, 0x7, 0x3, 0x3, 0xf1, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0037 "7" */
    0xff, 0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30,
    0x18, 0x18, 0xc, 0xc, 0x6, 0x6, 0x0,

    /* U+0038 "8" */
    0x3c, 0x33, 0x30, 0xd8, 0x6c, 0x33, 0x30, 0xf0,
    0xc6, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0039 "9" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xd, 0x8c,
    0x7e, 0x6, 0x2, 0x3, 0x3, 0x3, 0x0,

    /* U+003A ":" */
    0xf0, 0x3, 0xc0,

    /* U+003B ";" */
    0xf0, 0x3, 0xd8,

    /* U+003C "<" */
    0x0, 0xc, 0x63, 0xe, 0x7, 0x3, 0x81,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x1, 0x80, 0xc0, 0x60, 0xe7, 0x38, 0x40,

    /* U+003F "?" */
    0x79, 0x1c, 0x18, 0x30, 0xe3, 0xc, 0x10, 0x20,
    0x0, 0x1, 0x83, 0x0,

    /* U+0040 "@" */
    0xf, 0x80, 0x83, 0x8, 0x4, 0x80, 0x18, 0x3c,
    0xc2, 0x66, 0x22, 0x31, 0x11, 0x89, 0x94, 0x37,
    0x10, 0x0, 0xc0, 0x3, 0x83, 0x7, 0xe0,

    /* U+0041 "A" */
    0x6, 0x0, 0x70, 0xf, 0x0, 0x90, 0x19, 0x81,
    0x88, 0x10, 0xc3, 0xc, 0x3f, 0xc6, 0x6, 0x60,
    0x24, 0x3, 0xc0, 0x30,

    /* U+0042 "B" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0x1b, 0xf9,
    0x86, 0xc1, 0xe0, 0xf0, 0x78, 0x6f, 0xe0,

    /* U+0043 "C" */
    0xf, 0xc7, 0xd, 0x80, 0x30, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0xc, 0x1, 0x80, 0x18,
    0x30, 0xf8,

    /* U+0044 "D" */
    0xfe, 0x18, 0x33, 0x3, 0x60, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0x1b, 0x3, 0x60,
    0xcf, 0xe0,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0xf, 0xc6, 0x1d, 0x80, 0x30, 0xc, 0x1, 0x80,
    0x30, 0x6, 0xf, 0xc0, 0x6c, 0xd, 0x81, 0x98,
    0x70, 0xfc,

    /* U+0048 "H" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xff, 0xfe, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3c, 0x6,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc6, 0xf0,

    /* U+004B "K" */
    0xc0, 0xd8, 0x33, 0xc, 0x63, 0xc, 0xc1, 0x98,
    0x3e, 0x6, 0x60, 0xc6, 0x18, 0x63, 0xc, 0x60,
    0xcc, 0xc,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+004D "M" */
    0xc0, 0xf, 0x80, 0x7e, 0x1, 0xfc, 0xf, 0xd0,
    0x2f, 0x61, 0xbc, 0xc4, 0xf1, 0x33, 0xc7, 0x8f,
    0xc, 0x3c, 0x30, 0xf0, 0x3, 0xc0, 0xc,

    /* U+004E "N" */
    0xc0, 0x78, 0xf, 0x81, 0xf8, 0x3d, 0x87, 0x98,
    0xf1, 0x1e, 0x33, 0xc3, 0x78, 0x3f, 0x3, 0xe0,
    0x3c, 0x6,

    /* U+004F "O" */
    0xf, 0x81, 0x83, 0x18, 0xc, 0xc0, 0x6c, 0x1,
    0xe0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1b, 0x1,
    0x98, 0xc, 0x60, 0xc0, 0xf8, 0x0,

    /* U+0050 "P" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xd,
    0xfc, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x0,

    /* U+0051 "Q" */
    0xf, 0x80, 0xc1, 0x86, 0x3, 0x18, 0xc, 0xc0,
    0x1b, 0x0, 0x6c, 0x1, 0xb0, 0x6, 0xc0, 0x19,
    0x80, 0xc6, 0x3, 0xc, 0x18, 0xf, 0xc0, 0x1,
    0x80, 0x3, 0x0, 0x6,

    /* U+0052 "R" */
    0xfe, 0x30, 0xcc, 0x1b, 0x6, 0xc1, 0xb0, 0x6c,
    0x33, 0xf0, 0xcc, 0x31, 0x8c, 0x33, 0x6, 0xc0,
    0xc0,

    /* U+0053 "S" */
    0x1f, 0x18, 0x98, 0xc, 0x7, 0x3, 0xe0, 0xfc,
    0xf, 0x1, 0x80, 0xc0, 0x6c, 0x63, 0xe0,

    /* U+0054 "T" */
    0xff, 0xc3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x0,

    /* U+0055 "U" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x36, 0x19, 0x86, 0x1e,
    0x0,

    /* U+0056 "V" */
    0xc0, 0x34, 0x3, 0x60, 0x66, 0x6, 0x30, 0x43,
    0xc, 0x10, 0xc1, 0x98, 0x9, 0x80, 0xd0, 0xf,
    0x0, 0x70, 0x6, 0x0,

    /* U+0057 "W" */
    0xc0, 0xc0, 0xd0, 0x30, 0x36, 0xe, 0x9, 0x87,
    0x86, 0x21, 0xa1, 0x8c, 0x4c, 0x63, 0x33, 0x30,
    0xcc, 0x4c, 0x1a, 0x1b, 0x7, 0x86, 0x81, 0xe0,
    0xe0, 0x30, 0x38, 0xc, 0xc, 0x0,

    /* U+0058 "X" */
    0x60, 0x6c, 0x18, 0xc3, 0xc, 0xc1, 0xb0, 0x1e,
    0x3, 0x80, 0x78, 0x19, 0x6, 0x30, 0xc3, 0x30,
    0x6c, 0x6,

    /* U+0059 "Y" */
    0x60, 0x66, 0x6, 0x30, 0xc3, 0xc, 0x19, 0x80,
    0xd0, 0xf, 0x0, 0x60, 0x6, 0x0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0,

    /* U+005A "Z" */
    0x7f, 0xc0, 0x70, 0x18, 0xc, 0x7, 0x1, 0x80,
    0xc0, 0x70, 0x38, 0xe, 0x7, 0x3, 0x80, 0xff,
    0xc0,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,

    /* U+005C "\\" */
    0x81, 0x81, 0x3, 0x2, 0x4, 0x4, 0x8, 0x18,
    0x10, 0x30, 0x20, 0x40, 0x40,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x8, 0x18, 0x3c, 0x24, 0x62, 0x43,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0xc6, 0x30,

    /* U+0061 "a" */
    0x3c, 0x8c, 0x18, 0x33, 0xfc, 0xf1, 0xe7, 0x76,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xdc, 0xe6, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0063 "c" */
    0x3e, 0x62, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x63,
    0x3e,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x3, 0x3f, 0x63, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x67, 0x3b,

    /* U+0065 "e" */
    0x3c, 0x62, 0xc1, 0xff, 0xc0, 0xc0, 0xc0, 0x63,
    0x3e,

    /* U+0066 "f" */
    0x3b, 0x18, 0xcf, 0xb1, 0x8c, 0x63, 0x18, 0xc6,
    0x0,

    /* U+0067 "g" */
    0x7f, 0xe1, 0xb0, 0xd8, 0x63, 0xe2, 0x1, 0x0,
    0xfe, 0xc1, 0xe0, 0xf8, 0xc7, 0xc0,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xde, 0xe7, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xd8, 0x6, 0xdb, 0x6d, 0xb6,

    /* U+006A "j" */
    0x66, 0x0, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3e,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc3, 0xc6, 0xcc, 0xd8,
    0xf0, 0xd8, 0xcc, 0xc6, 0xc3,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+006D "m" */
    0xdd, 0xee, 0x73, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x30,

    /* U+006E "n" */
    0xde, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3,

    /* U+006F "o" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0070 "p" */
    0xdc, 0xe6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe6,
    0xfc, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x3f, 0x67, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x67,
    0x3b, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xdf, 0x8c, 0x30, 0xc3, 0xc, 0x30, 0xc0,

    /* U+0073 "s" */
    0x7b, 0xc, 0x38, 0x78, 0x70, 0xe3, 0x78,

    /* U+0074 "t" */
    0x23, 0x19, 0xf6, 0x31, 0x8c, 0x63, 0x18, 0x70,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7,
    0x7b,

    /* U+0076 "v" */
    0xc1, 0xa0, 0x98, 0xc4, 0x63, 0x21, 0xb0, 0x50,
    0x38, 0xc, 0x0,

    /* U+0077 "w" */
    0xc3, 0xd, 0xc, 0x26, 0x71, 0x99, 0x66, 0x24,
    0x90, 0xb2, 0xc3, 0x8f, 0x6, 0x18, 0x18, 0x60,

    /* U+0078 "x" */
    0x61, 0x31, 0x8d, 0x83, 0x81, 0xc0, 0xa0, 0xd8,
    0xc6, 0x41, 0x0,

    /* U+0079 "y" */
    0xc1, 0xb0, 0x98, 0xc4, 0x63, 0x20, 0xb0, 0x70,
    0x38, 0x8, 0xc, 0x4, 0x6, 0x0,

    /* U+007A "z" */
    0xfe, 0x18, 0x30, 0xc3, 0x4, 0x18, 0x60, 0xfe,

    /* U+007B "{" */
    0x3b, 0x18, 0xc6, 0x31, 0x8c, 0x83, 0x18, 0xc6,
    0x31, 0x87,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xe1, 0x8c, 0x63, 0x18, 0xc6, 0x9, 0x8c, 0x63,
    0x18, 0xdc,

    /* U+007E "~" */
    0x1, 0xb8, 0xb3, 0xd0, 0x0,

    /* U+00B0 "°" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0,

    /* U+00BC "¼" */
    0x20, 0x46, 0xc, 0x20, 0x82, 0x18, 0x21, 0x2,
    0x20, 0x76, 0x0, 0x46, 0x8, 0xa0, 0x92, 0x11,
    0xf3, 0x2, 0x0, 0x20,

    /* U+00BD "½" */
    0x20, 0x4c, 0x10, 0x82, 0x10, 0x82, 0x30, 0x44,
    0x1d, 0x0, 0x26, 0x9, 0x23, 0x4, 0x41, 0x10,
    0x42, 0x1e,

    /* U+00BE "¾" */
    0x60, 0x49, 0xc, 0x10, 0x82, 0x10, 0x91, 0xe,
    0x20, 0x6, 0x60, 0x46, 0x8, 0xa1, 0x92, 0x11,
    0xf2, 0x2, 0x40, 0x20
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 56, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 99, .box_w = 2, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 114, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 8, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 167, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 45, .adv_w = 226, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 202, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 66, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 88, .adv_w = 86, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 97, .adv_w = 86, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 106, .adv_w = 115, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 110, .adv_w = 167, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 119, .adv_w = 61, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 120, .adv_w = 100, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 121, .adv_w = 61, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 107, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 135, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 167, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 167, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 73, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 73, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 293, .adv_w = 167, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 300, .adv_w = 167, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 304, .adv_w = 167, .box_w = 7, .box_h = 8, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 311, .adv_w = 115, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 237, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 346, .adv_w = 196, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 186, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 197, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 217, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 167, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 163, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 211, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 218, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 88, .box_w = 2, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 196, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 148, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 265, .box_w = 14, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 218, .box_w = 11, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 230, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 230, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 630, .adv_w = 185, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 647, .adv_w = 153, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 170, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 210, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 196, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 716, .adv_w = 293, .box_w = 18, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 185, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 181, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 180, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 86, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 809, .adv_w = 108, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 822, .adv_w = 86, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 830, .adv_w = 167, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 836, .adv_w = 113, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 837, .adv_w = 88, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 839, .adv_w = 146, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 161, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 860, .adv_w = 134, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 161, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 882, .adv_w = 151, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 891, .adv_w = 97, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 147, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 914, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 74, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 932, .adv_w = 73, .box_w = 4, .box_h = 16, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 940, .adv_w = 151, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 953, .adv_w = 74, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 236, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 971, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 980, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1003, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1015, .adv_w = 116, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1022, .adv_w = 125, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1029, .adv_w = 107, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1037, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 147, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1057, .adv_w = 221, .box_w = 14, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1073, .adv_w = 145, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1084, .adv_w = 147, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1098, .adv_w = 133, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 86, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1116, .adv_w = 86, .box_w = 1, .box_h = 17, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1119, .adv_w = 86, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1129, .adv_w = 167, .box_w = 9, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1134, .adv_w = 114, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 1139, .adv_w = 205, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1159, .adv_w = 205, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1177, .adv_w = 205, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0xc, 0xd, 0xe
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 15, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 0, 1, 0, 3, 4, 3,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 6, 7, 0, 8, 6, 0, 9,
    0, 0, 0, 10, 11, 12, 0, 0,
    6, 13, 6, 14, 0, 15, 10, 5,
    16, 11, 17, 18, 2, 7, 0, 0,
    0, 0, 19, 20, 0, 0, 20, 21,
    0, 19, 0, 0, 22, 0, 19, 19,
    20, 20, 0, 23, 0, 0, 0, 24,
    25, 22, 24, 0, 2, 0, 0, 0,
    1, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 2,
    1, 0, 3, 1, 0, 4, 5, 4,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, 6, 0, 0, 0,
    7, 8, 2, 0, 8, 0, 0, 0,
    8, 0, 0, 9, 0, 0, 0, 0,
    8, 0, 8, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 0, 12, 3, 0,
    0, 0, 17, 0, 18, 18, 18, 19,
    20, 0, 0, 0, 0, 0, 6, 6,
    18, 6, 18, 6, 21, 22, 6, 23,
    24, 25, 23, 26, 0, 0, 3, 0,
    1, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -26, 0, -33, -26, 0, 0, -7,
    0, 0, 0, 7, 7, 0, 4, 0,
    -9, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, -33, 0, 0, 0,
    -20, 0, 0, -8, 0, -26, 0, -26,
    -18, 0, -22, 0, 0, 0, 0, 0,
    0, 0, -19, -9, 0, 0, -26, -7,
    0, -20, 0, 0, 0, 0, 0, -26,
    0, -16, -5, -9, -23, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    7, -20, 0, -28, -16, -13, 7, -7,
    -22, 0, 0, 0, 0, 0, 0, 0,
    -17, -17, -4, -20, -15, -6, -7, 0,
    -7, -12, -7, -6, -6, -8, 0, 0,
    0, 0, 0, -14, 0, -7, 0, -4,
    -12, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -26, 0, 0, 0,
    -7, 0, -8, -6, 7, -19, -8, -20,
    -12, 0, -24, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, 0, -22, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -19, 0, -26, 0, -9, 4, 0,
    -29, 0, 0, 0, 0, 0, 0, 0,
    0, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -8, 0, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, -7, 0,
    0, -12, -10, -8, 0, 0, -42, 0,
    0, 8, -29, 0, -7, -12, 0, -25,
    0, -26, -22, 0, -31, 0, 0, -5,
    0, 0, 0, 0, -16, -12, 0, 0,
    0, -20, 0, -36, 0, 0, 0, 0,
    -26, 0, 0, 0, 0, 0, 0, 0,
    -7, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, -7, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -19, 0, -26,
    -26, -23, 0, -14, -29, 0, 0, 0,
    0, 0, 0, 0, -36, -30, 0, -27,
    -23, 0, -26, -20, -21, -17, 7, -14,
    0, -18, -5, 0, 5, 0, -15, 0,
    0, 0, 0, 0, 0, 0, -13, -5,
    0, -14, -7, 0, 0, 0, 0, 0,
    4, -24, 0, -22, -23, -18, 5, -12,
    -29, 0, 0, 0, 0, 0, 0, 0,
    -18, -23, 0, -25, -18, 0, -14, -13,
    -19, 0, 0, 0, 0, 0, -10, 0,
    5, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, 0, -4, 0,
    -6, 0, 0, 0, -10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, -2, 0, 0, -13, 0,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, -17, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, -9, 0,
    10, 0, 0, -19, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -19,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -12,
    0, -19, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 25,
    .right_class_cnt     = 26,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_lato18 = {
#else
lv_font_t ui_font_lato18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_LATO18*/

