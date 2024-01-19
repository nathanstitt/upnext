#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ASSET_SNOW
#define LV_ATTRIBUTE_IMG_ASSET_SNOW
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ASSET_SNOW uint8_t asset_snow_map[] = {
  0x00, 0x00, 0x00, 0x00, 	/*Color of index 0*/
  0xfe, 0xfe, 0xfe, 0x0c, 	/*Color of index 1*/
  0xfe, 0xfe, 0xfe, 0x2f, 	/*Color of index 2*/
  0xfe, 0xfe, 0xfe, 0x48, 	/*Color of index 3*/
  0xfe, 0xfe, 0xfe, 0x68, 	/*Color of index 4*/
  0xfe, 0xfe, 0xfe, 0x97, 	/*Color of index 5*/
  0xfe, 0xfe, 0xfe, 0xc1, 	/*Color of index 6*/
  0xfe, 0xfe, 0xfe, 0xe2, 	/*Color of index 7*/
  0xfe, 0xfe, 0xfe, 0xfc, 	/*Color of index 8*/
  0xed, 0xc8, 0x2f, 0x0e, 	/*Color of index 9*/
  0xec, 0xc3, 0x31, 0x31, 	/*Color of index 10*/
  0xeb, 0xc3, 0x32, 0x5d, 	/*Color of index 11*/
  0xeb, 0xc3, 0x31, 0x8e, 	/*Color of index 12*/
  0xeb, 0xc3, 0x31, 0xc0, 	/*Color of index 13*/
  0xeb, 0xc4, 0x33, 0xeb, 	/*Color of index 14*/
  0xeb, 0xc3, 0x31, 0xfe, 	/*Color of index 15*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xbd, 0xde, 0xee, 0xdc, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x9d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x00, 0x9a, 0xba, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x09, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcd, 0xff, 0xff, 0xfd, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe9, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x90, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xad, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0x90, 0x00, 0x00, 
  0x00, 0x9c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xeb, 0x00, 0x00, 
  0x09, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0x00, 
  0x0c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x00, 
  0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 
  0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 
  0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 
  0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
  0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
  0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 
  0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x90, 
  0x9d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
  0x0a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd9, 0x00, 
  0x00, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xa0, 0x00, 
  0x00, 0x0a, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0x00, 0x00, 
  0x00, 0x00, 0x0a, 0xcd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xc9, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x10, 0x05, 0x82, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x48, 0x74, 0x15, 0x83, 0x15, 0x88, 0x10, 0x00, 0x00, 0x00, 0x01, 0x11, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x70, 0x00, 0x00, 0x00, 0x00, 0x15, 0x88, 0x66, 0x85, 0x88, 0x73, 0x00, 0x00, 0x00, 0x00, 0x02, 0x85, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x88, 0x88, 0x84, 0x10, 0x00, 0x00, 0x00, 0x00, 0x02, 0x85, 0x00, 0x00, 0x00, 
  0x23, 0x00, 0x08, 0x70, 0x01, 0x42, 0x00, 0x00, 0x00, 0x02, 0x78, 0x88, 0x51, 0x00, 0x00, 0x00, 0x03, 0x20, 0x02, 0x85, 0x00, 0x14, 0x10, 
  0x68, 0x62, 0x07, 0x70, 0x26, 0x85, 0x00, 0x00, 0x01, 0x58, 0x88, 0x88, 0x87, 0x41, 0x00, 0x00, 0x18, 0x85, 0x12, 0x85, 0x13, 0x78, 0x40, 
  0x26, 0x88, 0x58, 0x75, 0x88, 0x62, 0x00, 0x00, 0x37, 0x87, 0x45, 0x83, 0x58, 0x86, 0x10, 0x00, 0x13, 0x78, 0x85, 0x86, 0x68, 0x85, 0x10, 
  0x00, 0x37, 0x88, 0x88, 0x74, 0x00, 0x00, 0x00, 0x28, 0x51, 0x05, 0x83, 0x02, 0x66, 0x10, 0x00, 0x00, 0x14, 0x88, 0x88, 0x86, 0x20, 0x00, 
  0x00, 0x04, 0x88, 0x88, 0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x82, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x58, 0x88, 0x72, 0x00, 0x00, 
  0x02, 0x68, 0x88, 0x88, 0x86, 0x20, 0x00, 0x00, 0x00, 0x00, 0x05, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x88, 0x88, 0x88, 0x51, 0x00, 
  0x58, 0x86, 0x37, 0x73, 0x68, 0x75, 0x00, 0x00, 0x00, 0x00, 0x03, 0x52, 0x00, 0x00, 0x00, 0x00, 0x16, 0x88, 0x53, 0x85, 0x47, 0x87, 0x30, 
  0x57, 0x41, 0x08, 0x70, 0x14, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x63, 0x02, 0x85, 0x01, 0x57, 0x30, 
  0x11, 0x00, 0x07, 0x70, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x02, 0x85, 0x00, 0x01, 0x00, 
  0x00, 0x00, 0x08, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x85, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x05, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x54, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t asset_snow = {
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 45,
  .header.h = 45,
  .data_size = 1099,
  .data = asset_snow_map,
};