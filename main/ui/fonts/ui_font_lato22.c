/*******************************************************************************
 * Size: 22 px
 * Bpp: 1
 * Opts: --bpp 1 --size 22 --font /Users/nas/SquareLine/assets/Lato-Regular.ttf -o /Users/nas/SquareLine/assets/ui_font_lato22.c --format lvgl -r 0x20-0x7f --symbols :@°&/¾½¼⛆❄\!()., --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_LATO22
#define UI_FONT_LATO22 1
#endif

#if UI_FONT_LATO22

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xdb, 0x6d, 0xb6, 0xd8, 0x1, 0xf8,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xf3, 0xcc,

    /* U+0023 "#" */
    0x8, 0xc3, 0x10, 0x62, 0xc, 0xcf, 0xfe, 0x23,
    0xc, 0x41, 0x88, 0x33, 0x1f, 0xf8, 0x8c, 0x31,
    0x6, 0x20, 0xcc, 0x11, 0x80,

    /* U+0024 "$" */
    0x2, 0x0, 0x40, 0x8, 0x7, 0xc3, 0xfc, 0xe4,
    0x98, 0x83, 0x10, 0x72, 0x7, 0xc0, 0x7e, 0x2,
    0xe0, 0x46, 0x8, 0xc1, 0x1a, 0x27, 0x7f, 0xc7,
    0xe0, 0x30, 0x6, 0x0, 0x80,

    /* U+0025 "%" */
    0x38, 0xc, 0x6c, 0x8, 0xc6, 0x18, 0xc6, 0x30,
    0xc6, 0x60, 0x6c, 0x40, 0x38, 0xc0, 0x1, 0x80,
    0x3, 0x3c, 0x2, 0x66, 0x6, 0xc3, 0xc, 0xc3,
    0x18, 0xc3, 0x30, 0x66, 0x30, 0x3c,

    /* U+0026 "&" */
    0xf, 0x0, 0x63, 0x3, 0xc, 0xc, 0x0, 0x30,
    0x0, 0x60, 0x1, 0xc0, 0xf, 0x84, 0x67, 0x13,
    0xe, 0xcc, 0x1f, 0x30, 0x38, 0xc0, 0x71, 0x87,
    0xe3, 0xf1, 0xc0,

    /* U+0027 "'" */
    0xff, 0xc0,

    /* U+0028 "(" */
    0x1, 0x36, 0x66, 0xcc, 0xcc, 0xcc, 0xcc, 0x66,
    0x63, 0x31,

    /* U+0029 ")" */
    0x8, 0xc6, 0x66, 0x33, 0x33, 0x33, 0x33, 0x66,
    0x6c, 0xc8,

    /* U+002A "*" */
    0x10, 0x21, 0xf0, 0x87, 0xc2, 0x4, 0x0,

    /* U+002B "+" */
    0xc, 0x1, 0x80, 0x30, 0x6, 0xf, 0xfe, 0x18,
    0x3, 0x0, 0x60, 0xc, 0x1, 0x80,

    /* U+002C "," */
    0xec, 0xa0,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x1, 0x3, 0x2, 0x6, 0x4, 0xc, 0xc, 0x8,
    0x18, 0x10, 0x30, 0x30, 0x20, 0x60, 0x40, 0xc0,
    0x80,

    /* U+0030 "0" */
    0x1f, 0x6, 0x31, 0x83, 0x30, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xb0,
    0x66, 0xc, 0x63, 0x7, 0xc0,

    /* U+0031 "1" */
    0xc, 0xe, 0xf, 0xd, 0x8c, 0xc0, 0x60, 0x30,
    0x18, 0xc, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x61,
    0xfe,

    /* U+0032 "2" */
    0x1f, 0xe, 0x31, 0x83, 0x60, 0x60, 0xc, 0x1,
    0x80, 0x60, 0x1c, 0x7, 0x1, 0xc0, 0x70, 0x1c,
    0x7, 0x1, 0xff, 0xff, 0xf8,

    /* U+0033 "3" */
    0x1f, 0x1c, 0x66, 0xf, 0x3, 0x0, 0xc0, 0x60,
    0xf0, 0x6, 0x0, 0xc0, 0x30, 0xf, 0x3, 0xc1,
    0x98, 0xe3, 0xe0,

    /* U+0034 "4" */
    0x1, 0xc0, 0x1c, 0x3, 0xc0, 0x6c, 0xc, 0xc0,
    0xcc, 0x18, 0xc3, 0xc, 0x60, 0xce, 0xc, 0xff,
    0xf0, 0xc, 0x0, 0xc0, 0xc, 0x0, 0xc0,

    /* U+0035 "5" */
    0x3f, 0xcf, 0xe6, 0x1, 0x80, 0x60, 0x1f, 0x80,
    0x38, 0x7, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x1,
    0xb0, 0xc7, 0xe0,

    /* U+0036 "6" */
    0x3, 0x80, 0xe0, 0x38, 0x6, 0x1, 0x80, 0x60,
    0x1b, 0xe3, 0x8e, 0xe0, 0xf8, 0xf, 0x1, 0xe0,
    0x36, 0xc, 0xe3, 0x87, 0xc0,

    /* U+0037 "7" */
    0xff, 0xff, 0xfc, 0x1, 0x0, 0x60, 0x18, 0x3,
    0x0, 0xc0, 0x18, 0x6, 0x0, 0xc0, 0x30, 0xe,
    0x1, 0x80, 0x70, 0xc, 0x0,

    /* U+0038 "8" */
    0x3f, 0xc, 0x33, 0x3, 0x60, 0x6c, 0xc, 0xc3,
    0x7, 0xc3, 0x8e, 0xe0, 0xd8, 0xf, 0x1, 0xe0,
    0x3e, 0xe, 0xe3, 0x87, 0xc0,

    /* U+0039 "9" */
    0x1e, 0x18, 0x6c, 0xb, 0x3, 0xc0, 0xf0, 0x36,
    0x1c, 0xfe, 0x3, 0x80, 0xc0, 0x60, 0x38, 0xc,
    0x6, 0x3, 0x80,

    /* U+003A ":" */
    0xf0, 0x0, 0x3c,

    /* U+003B ";" */
    0xf0, 0x0, 0x3d, 0xa0,

    /* U+003C "<" */
    0x0, 0x81, 0xc3, 0x87, 0xe, 0x3, 0x80, 0x70,
    0xe, 0x3, 0x80, 0x40,

    /* U+003D "=" */
    0xff, 0x80, 0x0, 0x0, 0xf, 0xf8,

    /* U+003E ">" */
    0x80, 0x70, 0x1e, 0x3, 0xc0, 0x78, 0x38, 0x70,
    0xe0, 0xc0, 0x0, 0x0,

    /* U+003F "?" */
    0x7c, 0xc6, 0x3, 0x3, 0x3, 0x6, 0x1c, 0x18,
    0x30, 0x10, 0x0, 0x0, 0x0, 0x30, 0x30,

    /* U+0040 "@" */
    0x3, 0xf0, 0x6, 0x6, 0x6, 0x1, 0x86, 0x0,
    0x66, 0x1f, 0x1b, 0x18, 0x8f, 0x18, 0xc7, 0x98,
    0x63, 0xcc, 0x21, 0xe6, 0x31, 0xb3, 0x18, 0xd8,
    0xf3, 0x86, 0x0, 0x1, 0x80, 0x0, 0xe0, 0x8,
    0x18, 0x1c, 0x3, 0xf8, 0x0,

    /* U+0041 "A" */
    0x3, 0x80, 0x7, 0x0, 0x1b, 0x0, 0x36, 0x0,
    0xec, 0x1, 0x8c, 0x3, 0x18, 0xe, 0x38, 0x18,
    0x30, 0x70, 0x70, 0xff, 0xe1, 0x80, 0xc6, 0x0,
    0xcc, 0x1, 0xb8, 0x3, 0x80,

    /* U+0042 "B" */
    0xff, 0x98, 0x1b, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x37, 0xf8, 0xc0, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x81, 0xbf, 0xc0,

    /* U+0043 "C" */
    0x7, 0xe0, 0xff, 0x8e, 0xe, 0xe0, 0x6, 0x0,
    0x60, 0x3, 0x0, 0x18, 0x0, 0xc0, 0x6, 0x0,
    0x18, 0x0, 0xe0, 0x3, 0x83, 0x8f, 0xf8, 0x1f,
    0x0,

    /* U+0044 "D" */
    0xff, 0x83, 0x1, 0x8c, 0x3, 0x30, 0x6, 0xc0,
    0x1b, 0x0, 0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf,
    0x0, 0x3c, 0x1, 0xb0, 0x6, 0xc0, 0x33, 0x1,
    0x8f, 0xf8, 0x0,

    /* U+0045 "E" */
    0xff, 0xf0, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0xfe, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0xf, 0xfc,

    /* U+0046 "F" */
    0xff, 0xf0, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0xfe, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0xc, 0x0,

    /* U+0047 "G" */
    0x7, 0xe0, 0x7f, 0xe3, 0x81, 0xdc, 0x0, 0x60,
    0x3, 0x0, 0xc, 0x0, 0x30, 0x0, 0xc0, 0x7f,
    0x0, 0x34, 0x0, 0xd8, 0x3, 0x30, 0xc, 0x60,
    0x70, 0x7f, 0x80,

    /* U+0048 "H" */
    0xc0, 0x1e, 0x0, 0xf0, 0x7, 0x80, 0x3c, 0x1,
    0xe0, 0xf, 0x0, 0x7f, 0xff, 0xc0, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x3c, 0x1, 0xe0, 0xf, 0x0,
    0x60,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc, 0x18, 0x30, 0xdf, 0xbe, 0x0,

    /* U+004B "K" */
    0xc0, 0x7c, 0xe, 0xc1, 0xcc, 0x18, 0xc3, 0xc,
    0x60, 0xcc, 0xf, 0xc0, 0xce, 0xc, 0x60, 0xc3,
    0xc, 0x18, 0xc0, 0xcc, 0x6, 0xc0, 0x30,

    /* U+004C "L" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7, 0xff,
    0xfe,

    /* U+004D "M" */
    0xc0, 0x3, 0xe0, 0x7, 0xe0, 0x7, 0xf0, 0xf,
    0xd8, 0x1b, 0xd8, 0x1b, 0xcc, 0x33, 0xc4, 0x33,
    0xc6, 0x63, 0xc3, 0x43, 0xc3, 0xc3, 0xc1, 0x83,
    0xc1, 0x83, 0xc0, 0x3, 0xc0, 0x3,

    /* U+004E "N" */
    0xc0, 0x1f, 0x0, 0xfc, 0x7, 0xe0, 0x3d, 0x81,
    0xe6, 0xf, 0x18, 0x78, 0xe3, 0xc3, 0x1e, 0xc,
    0xf0, 0x37, 0x80, 0xfc, 0x7, 0xe0, 0x1f, 0x0,
    0x60,

    /* U+004F "O" */
    0x7, 0xc0, 0x3f, 0xe0, 0xe0, 0xe3, 0x0, 0x66,
    0x0, 0xd8, 0x0, 0xf0, 0x1, 0xe0, 0x3, 0xc0,
    0x7, 0x80, 0xd, 0x80, 0x33, 0x0, 0x63, 0x83,
    0x83, 0xfe, 0x1, 0xf0, 0x0,

    /* U+0050 "P" */
    0xfe, 0x30, 0x6c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0x1f, 0xe, 0xfe, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0xc, 0x0,

    /* U+0051 "Q" */
    0x7, 0xc0, 0x1f, 0xf0, 0x38, 0x38, 0x60, 0xc,
    0x60, 0xc, 0xc0, 0x6, 0xc0, 0x6, 0xc0, 0x6,
    0xc0, 0x6, 0xc0, 0x6, 0x60, 0xc, 0x60, 0xc,
    0x38, 0x38, 0x1f, 0xf0, 0x7, 0xf8, 0x0, 0x1c,
    0x0, 0xc, 0x0, 0x6,

    /* U+0052 "R" */
    0xff, 0x18, 0x33, 0x3, 0x60, 0x6c, 0xd, 0x81,
    0xb0, 0x67, 0xf0, 0xc6, 0x18, 0xe3, 0xc, 0x60,
    0xcc, 0x1d, 0x81, 0xb0, 0x18,

    /* U+0053 "S" */
    0xf, 0xc6, 0x19, 0x80, 0x30, 0x6, 0x0, 0xf0,
    0xf, 0xc0, 0xfe, 0x7, 0xe0, 0x1c, 0x1, 0x80,
    0x34, 0x5, 0xc1, 0x8f, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0x6, 0x0, 0x60, 0x6, 0x0,
    0x60, 0x6, 0x0, 0x60, 0x6, 0x0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0, 0x60, 0x6, 0x0,

    /* U+0055 "U" */
    0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3e, 0x7, 0x70, 0xe3, 0xfc, 0x1f, 0x80,

    /* U+0056 "V" */
    0xe0, 0xe, 0xc0, 0x19, 0x80, 0x31, 0x80, 0xc3,
    0x1, 0x87, 0x7, 0x6, 0xc, 0xc, 0x38, 0xc,
    0x60, 0x18, 0xc0, 0x1b, 0x0, 0x36, 0x0, 0x6c,
    0x0, 0x70, 0x0, 0xe0, 0x0,

    /* U+0057 "W" */
    0xe0, 0x30, 0xd, 0x80, 0xe0, 0x36, 0x3, 0x81,
    0x9c, 0x1e, 0x6, 0x30, 0x6c, 0x18, 0xc3, 0x30,
    0xc3, 0x8c, 0xc3, 0x6, 0x31, 0x8c, 0x19, 0x86,
    0x60, 0x66, 0x19, 0x80, 0xd8, 0x36, 0x3, 0xc0,
    0xf0, 0xf, 0x1, 0xc0, 0x1c, 0x7, 0x0, 0x60,
    0x18, 0x0,

    /* U+0058 "X" */
    0x60, 0x19, 0xc0, 0xe3, 0x83, 0x6, 0x18, 0xc,
    0xe0, 0x3b, 0x0, 0x78, 0x1, 0xe0, 0x7, 0x80,
    0x33, 0x1, 0xce, 0x6, 0x1c, 0x30, 0x31, 0xc0,
    0xe6, 0x1, 0xc0,

    /* U+0059 "Y" */
    0x60, 0x19, 0x80, 0x63, 0x3, 0xe, 0x1c, 0x18,
    0x60, 0x33, 0x0, 0xcc, 0x1, 0xe0, 0x3, 0x0,
    0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc,
    0x0, 0x30, 0x0,

    /* U+005A "Z" */
    0xff, 0xf0, 0x7, 0x0, 0xe0, 0x1c, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0xe, 0x1, 0xc0, 0x38,
    0x3, 0x0, 0x70, 0xe, 0x0, 0xff, 0xf0,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xcc, 0xf0,

    /* U+005C "\\" */
    0xc0, 0xc0, 0x40, 0x60, 0x20, 0x30, 0x30, 0x18,
    0x18, 0x8, 0xc, 0x4, 0x6, 0x6, 0x2, 0x3,
    0x1,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0xf0,

    /* U+005E "^" */
    0x18, 0xe, 0xd, 0x6, 0xc6, 0x22, 0x1b, 0x6,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0x61, 0x84,

    /* U+0061 "a" */
    0x3e, 0x31, 0x80, 0x60, 0x30, 0x18, 0xfd, 0xc7,
    0x83, 0xc1, 0xe1, 0xdf, 0x60,

    /* U+0062 "b" */
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x37, 0xce,
    0x1b, 0x6, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x6e, 0x3b, 0x78,

    /* U+0063 "c" */
    0x1f, 0x38, 0xd8, 0x18, 0xc, 0x6, 0x3, 0x1,
    0x80, 0x60, 0x38, 0xc7, 0xc0,

    /* U+0064 "d" */
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc7, 0xb7,
    0x1d, 0x83, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xd8, 0x36, 0x1c, 0xfb,

    /* U+0065 "e" */
    0x1f, 0x18, 0x66, 0xf, 0x3, 0xff, 0xf0, 0xc,
    0x3, 0x0, 0x60, 0x1c, 0x71, 0xf0,

    /* U+0066 "f" */
    0x1e, 0x70, 0xc1, 0x8f, 0xe6, 0xc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0067 "g" */
    0x1f, 0xe6, 0x79, 0x86, 0x30, 0xc6, 0x18, 0x66,
    0x7, 0x83, 0x0, 0x60, 0x7, 0xf1, 0x87, 0x60,
    0x6c, 0xc, 0xc3, 0xf, 0xc0,

    /* U+0068 "h" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0xf3, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf,
    0x7, 0x83,

    /* U+0069 "i" */
    0xfc, 0x1, 0xb6, 0xdb, 0x6d, 0xb6,

    /* U+006A "j" */
    0x39, 0xc0, 0x0, 0x18, 0xc6, 0x31, 0x8c, 0x63,
    0x18, 0xc6, 0x31, 0x8d, 0xc0,

    /* U+006B "k" */
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0x6c,
    0x33, 0x18, 0xcc, 0x36, 0xf, 0x83, 0x70, 0xce,
    0x31, 0x8c, 0x33, 0x6,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xde, 0x3c, 0xe3, 0xc6, 0xc1, 0x83, 0xc1, 0x83,
    0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83,
    0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83,

    /* U+006E "n" */
    0xde, 0x71, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x60,

    /* U+006F "o" */
    0x1f, 0xe, 0x39, 0x83, 0x60, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0x60, 0xce, 0x38, 0x7c, 0x0,

    /* U+0070 "p" */
    0xdf, 0x38, 0x6c, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc1, 0xb8, 0xed, 0xe3, 0x0, 0xc0,
    0x30, 0xc, 0x0,

    /* U+0071 "q" */
    0x1e, 0xdc, 0x76, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0x60, 0xd8, 0x73, 0xec, 0x3, 0x0,
    0xc0, 0x30, 0xc,

    /* U+0072 "r" */
    0xcf, 0xff, 0x86, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x0,

    /* U+0073 "s" */
    0x3e, 0x62, 0xc0, 0xc0, 0xf8, 0x7e, 0xf, 0x3,
    0x3, 0xc6, 0x7c,

    /* U+0074 "t" */
    0x10, 0x60, 0xc1, 0x8f, 0xe6, 0xc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0x47, 0x80,

    /* U+0075 "u" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xb1, 0xcf, 0x60,

    /* U+0076 "v" */
    0xc0, 0x6c, 0x19, 0x83, 0x18, 0x63, 0x18, 0x63,
    0x6, 0xc0, 0xd8, 0xf, 0x1, 0xc0, 0x18, 0x0,

    /* U+0077 "w" */
    0xc1, 0xc1, 0xb0, 0xe1, 0x98, 0x50, 0xcc, 0x68,
    0x63, 0x36, 0x61, 0x93, 0x30, 0xd8, 0x98, 0x2c,
    0x78, 0x1c, 0x3c, 0xe, 0xe, 0x3, 0x6, 0x0,

    /* U+0078 "x" */
    0x60, 0xc6, 0x38, 0xc6, 0xd, 0x80, 0xe0, 0x1c,
    0x6, 0xc0, 0xd8, 0x31, 0x8c, 0x19, 0x83, 0x0,

    /* U+0079 "y" */
    0xe0, 0x6c, 0x19, 0x83, 0x18, 0x63, 0x18, 0x33,
    0x6, 0xc0, 0xd8, 0xe, 0x1, 0xc0, 0x18, 0x6,
    0x0, 0xc0, 0x30, 0x6, 0x0,

    /* U+007A "z" */
    0xff, 0x7, 0x6, 0xc, 0x1c, 0x18, 0x30, 0x70,
    0x60, 0xc0, 0xff,

    /* U+007B "{" */
    0x3b, 0x18, 0xc6, 0x31, 0x8c, 0x64, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0xe,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xe1, 0x8c, 0x63, 0x18, 0xc6, 0x30, 0x4c, 0x63,
    0x18, 0xc6, 0x31, 0xb8,

    /* U+007E "~" */
    0x0, 0xc0, 0x37, 0x9f, 0x1e, 0xc0, 0x0,

    /* U+00B0 "°" */
    0x38, 0xdb, 0x1e, 0x3c, 0x6d, 0x8e, 0x0,

    /* U+00BC "¼" */
    0x30, 0x9, 0xc0, 0xcf, 0x2, 0xc, 0x18, 0x30,
    0x40, 0xc3, 0x3, 0x18, 0x3e, 0x40, 0x3, 0x18,
    0x8, 0x60, 0x62, 0x83, 0x1a, 0x8, 0x48, 0x63,
    0xf1, 0x0, 0x88, 0x2,

    /* U+00BD "½" */
    0x30, 0x11, 0xc0, 0x8f, 0x6, 0xc, 0x10, 0x30,
    0x80, 0xc6, 0x3, 0x10, 0xc, 0xc0, 0xfa, 0x78,
    0x19, 0x30, 0xc0, 0xc2, 0x3, 0x18, 0x18, 0x40,
    0xc3, 0x6, 0x18, 0x3f,

    /* U+00BE "¾" */
    0x78, 0x13, 0x30, 0xc0, 0xc2, 0xc, 0x18, 0xc,
    0x43, 0x32, 0x7, 0x98, 0x0, 0x46, 0x3, 0x18,
    0x18, 0xa0, 0x46, 0x83, 0x12, 0x8, 0x7c, 0x60,
    0x23, 0x0, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 68, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 121, .box_w = 3, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 140, .box_w = 6, .box_h = 5, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 11, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 204, .box_w = 11, .box_h = 21, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 61, .adv_w = 277, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 247, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 81, .box_w = 2, .box_h = 5, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 120, .adv_w = 106, .box_w = 4, .box_h = 20, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 130, .adv_w = 106, .box_w = 4, .box_h = 20, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 140, .adv_w = 141, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 147, .adv_w = 204, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 161, .adv_w = 75, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 163, .adv_w = 122, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 164, .adv_w = 75, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 131, .box_w = 8, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 182, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 204, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 204, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 204, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 204, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 204, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 204, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 89, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 89, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 391, .adv_w = 204, .box_w = 9, .box_h = 10, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 403, .adv_w = 204, .box_w = 9, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 409, .adv_w = 204, .box_w = 9, .box_h = 10, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 421, .adv_w = 140, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 289, .box_w = 17, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 473, .adv_w = 239, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 228, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 523, .adv_w = 241, .box_w = 13, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 548, .adv_w = 265, .box_w = 14, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 205, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 199, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 258, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 266, .box_w = 13, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 108, .box_w = 2, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 156, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 683, .adv_w = 240, .box_w = 12, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 181, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 324, .box_w = 16, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 266, .box_w = 13, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 281, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 215, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 826, .adv_w = 281, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 862, .adv_w = 227, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 187, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 904, .adv_w = 208, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 257, .box_w = 12, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 239, .box_w = 15, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 979, .adv_w = 359, .box_w = 22, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 226, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1048, .adv_w = 221, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1075, .adv_w = 220, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1098, .adv_w = 106, .box_w = 4, .box_h = 19, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1108, .adv_w = 132, .box_w = 8, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1125, .adv_w = 106, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1135, .adv_w = 204, .box_w = 9, .box_h = 7, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 1143, .adv_w = 139, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1145, .adv_w = 108, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 12},
    {.bitmap_index = 1147, .adv_w = 178, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1160, .adv_w = 197, .box_w = 10, .box_h = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1180, .adv_w = 164, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1193, .adv_w = 197, .box_w = 10, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 184, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1227, .adv_w = 119, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1241, .adv_w = 180, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1262, .adv_w = 196, .box_w = 9, .box_h = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1280, .adv_w = 90, .box_w = 3, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1286, .adv_w = 89, .box_w = 5, .box_h = 20, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 1299, .adv_w = 184, .box_w = 10, .box_h = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1319, .adv_w = 90, .box_w = 2, .box_h = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1323, .adv_w = 289, .box_w = 16, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1345, .adv_w = 196, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1358, .adv_w = 196, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1374, .adv_w = 194, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1393, .adv_w = 197, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1412, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1422, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1433, .adv_w = 131, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1447, .adv_w = 196, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1460, .adv_w = 180, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1476, .adv_w = 270, .box_w = 17, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1500, .adv_w = 177, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1516, .adv_w = 180, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1537, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1548, .adv_w = 106, .box_w = 5, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1560, .adv_w = 106, .box_w = 2, .box_h = 20, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 1565, .adv_w = 106, .box_w = 5, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1577, .adv_w = 204, .box_w = 10, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1584, .adv_w = 140, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 1591, .adv_w = 251, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1619, .adv_w = 251, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1647, .adv_w = 251, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = 0}
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
    0, -32, 0, -40, -31, 0, 0, -8,
    0, 0, 0, 8, 8, 0, 5, 0,
    -11, -16, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, -40, 0, 0, 0,
    -24, 0, 0, -10, 0, -32, 0, -32,
    -21, 0, -27, 0, 0, 0, 0, 0,
    0, 0, -23, -11, 0, 0, -31, -9,
    0, -24, 0, 0, 0, 0, 0, -32,
    0, -20, -6, -11, -28, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    8, -24, 0, -34, -20, -15, 8, -9,
    -27, 0, 0, 0, 0, 0, 0, 0,
    -20, -20, -5, -24, -19, -7, -8, 0,
    -9, -14, -8, -7, -7, -10, 0, 0,
    0, 0, 0, -17, 0, -9, 0, -5,
    -14, -12, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -32, 0, 0, 0,
    -9, 0, -10, -7, 9, -23, -10, -24,
    -15, 0, -29, 0, 0, 0, 0, 0,
    0, 0, -14, 0, 0, 0, 0, 0,
    0, 0, -26, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -23, 0, -32, 0, -11, 5, 0,
    -35, 0, 0, 0, 0, 0, 0, 0,
    0, -12, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -10, 0, -9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -11, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, -9, 0,
    0, -14, -12, -10, 0, 0, -51, 0,
    0, 10, -35, 0, -9, -14, 0, -30,
    0, -32, -27, 0, -37, 0, 0, -6,
    0, 0, 0, 0, -19, -14, 0, 0,
    0, -24, 0, -44, 0, 0, 0, 0,
    -32, 0, 0, 0, 0, 0, 0, 0,
    -9, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -9, -7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -23, 0, -32,
    -32, -28, 0, -17, -35, 0, 0, 0,
    0, 0, 0, 0, -44, -37, 0, -33,
    -29, 0, -32, -25, -25, -21, 8, -17,
    0, -21, -6, 0, 6, 0, -18, 0,
    0, 0, 0, 0, 0, 0, -15, -6,
    0, -17, -8, 0, 0, 0, 0, 0,
    5, -29, 0, -27, -28, -21, 6, -14,
    -35, 0, 0, 0, 0, 0, 0, 0,
    -23, -28, 0, -30, -23, 0, -18, -16,
    -23, 0, 0, 0, 0, 0, -12, 0,
    6, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -7, 0, 0, -5, 0,
    -7, 0, 0, 0, -13, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, -3, 0, 0, -16, 0,
    -6, 0, 0, 0, 0, 0, 0, 0,
    0, -20, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, -11, 0,
    12, 0, 0, -23, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -23,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -7, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -14,
    0, -23, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -11, 0, 0, 0, 0,
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
const lv_font_t ui_font_lato22 = {
#else
lv_font_t ui_font_lato22 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 22,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_LATO22*/

