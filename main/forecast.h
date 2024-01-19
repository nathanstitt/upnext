#pragma once

#include <lvgl.h>
#include "weather.h"

class Forecast {

public:
  Forecast(uint8_t index, lv_obj_t *dow, lv_obj_t *img, lv_obj_t *hl);

  void update(const OW::Daily &forecast);

    uint8_t index;
private:
    lv_obj_t *dow;
    lv_obj_t *img;
    lv_obj_t *hl;
};
