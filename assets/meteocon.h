#pragma once

#include <lvgl.h>
#include "weather_structs.h"

class Meteocon {

public:
  Meteocon(lv_obj_t *parent, const lv_font_t *font, lv_coord_t x, lv_coord_t y);

  void update(const OW::Daily &forecast);

private:
  lv_obj_t *screen;
  lv_coord_t x;
  lv_coord_t y;

  lv_obj_t *img;
  lv_obj_t *date;
  lv_obj_t *hilo;
  lv_obj_t *precip;
};
