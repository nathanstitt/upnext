#pragma once

#include "lvgl.h"
#include "calendar_events.h"
#include <string>
#include "upnext_config.h"

class CalendarUI {
public:
    CalendarUI(CalendarEvents* calendar);

    void setup(lv_obj_t* parent);

 //   void setCurrentEvent(std::string title);

    void tick();

private:

    lv_obj_t* screen;
    CalendarEvents* events;

    lv_obj_t* duration;
    lv_obj_t* time;
    lv_obj_t* title;
    lv_obj_t*  freedom_image;
    lv_obj_t*  headphones_image;

    std::chrono::system_clock::time_point last_poll;

};

