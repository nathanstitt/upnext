#include "calendar.h"

#include <chrono>
#include "fmt/format.h"
#include "fmt/chrono.h"
#include <iostream>

CalendarUI::CalendarUI(CalendarEvents* evs)
: events(evs) {}

LV_IMG_DECLARE(asset_cheers);
LV_IMG_DECLARE(asset_headphones);

void initOrReset(lv_style_t* obj) {
    if (obj->prop_cnt > 1)
        lv_style_reset(obj);
    else
        lv_style_init(obj);
}

void CalendarUI::setup(lv_obj_t* parent) {
    auto width   = lv_obj_get_width(parent);
    this->screen = lv_obj_create(parent);
    lv_obj_set_pos(this->screen, 0, 0);
    lv_obj_set_size(this->screen, width, lv_obj_get_height(parent) / 2);
    lv_obj_set_scrollbar_mode(this->screen, LV_SCROLLBAR_MODE_OFF);


    static lv_style_t screen_style;
    lv_style_set_radius(&screen_style, 0);
    lv_style_set_pad_all(&screen_style, 0);
    lv_style_set_border_width(&screen_style, 0);
    lv_style_set_bg_color(&screen_style, lv_color_make(0, 0, 0));
    lv_style_set_text_color(&screen_style, lv_color_make(0xff, 0xff, 0xff));

    lv_obj_add_style(this->screen, &screen_style, LV_PART_MAIN | LV_STATE_DEFAULT);


    static lv_style_t lg_font_style;
    initOrReset(&lg_font_style);
    lv_style_set_text_line_space(&lg_font_style, 12);
    lv_style_set_text_font(&lg_font_style, &font_lato_24); // lv_font_montserrat_40);
    lv_style_set_text_align(&lg_font_style, LV_TEXT_ALIGN_LEFT);


    static lv_style_t md_font_style;
    initOrReset(&md_font_style);
    lv_style_set_text_font(&md_font_style, &font_lato_18);
    lv_style_set_text_align(&md_font_style, LV_TEXT_ALIGN_LEFT);

    // lv_style_set_text_font(&lg_font_style, LV_FONT_MONTSERRAT_44);


    duration = lv_label_create(this->screen);
    lv_obj_set_pos(duration, 5, 5);
    lv_obj_set_size(duration, width - 60, 30);
    lv_label_set_text(duration, "20 minutes");
    lv_obj_add_style(duration, &md_font_style, LV_PART_MAIN | LV_STATE_DEFAULT);

    static lv_style_t right_aligned_style;
    initOrReset(&right_aligned_style);
    lv_style_set_text_align(&right_aligned_style, LV_TEXT_ALIGN_RIGHT);

    static lv_style_t center_aligned_style;
    initOrReset(&center_aligned_style);
    lv_style_set_text_align(&center_aligned_style, LV_TEXT_ALIGN_CENTER);

    this->time = lv_label_create(this->screen);
    lv_label_set_long_mode(this->time, LV_LABEL_LONG_CLIP);
    lv_obj_set_pos(this->time, width/2, 5);
    lv_obj_set_size(this->time, (width/2) - 10, 30);
    lv_label_set_text(this->time, "0:00am");

    //lv_label_set_align(time, LV_LABEL_ALIGN_RIGHT);

    lv_obj_add_style(time, &md_font_style, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_style(time, &right_aligned_style, LV_PART_MAIN | LV_STATE_DEFAULT);



    freedom_image = lv_img_create(this->screen);
    lv_img_set_src(freedom_image, &asset_cheers);
    lv_obj_set_pos(freedom_image, (width - 120)/2, 34);
    lv_obj_add_flag(freedom_image, LV_OBJ_FLAG_HIDDEN);


    headphones_image = lv_img_create(this->screen);
    lv_img_set_src(this->headphones_image, &asset_headphones);
    lv_obj_set_pos(this->headphones_image, (width - 80)/2, 34);
    lv_obj_add_flag(this->headphones_image, LV_OBJ_FLAG_HIDDEN);

    title = lv_label_create(this->screen);

    lv_obj_set_pos(title, 5, 130);
    lv_obj_set_size(title, width - 10, 90);
    lv_label_set_text(title, ""); // No more events today, party on!");

    lv_obj_add_style(title, &lg_font_style, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(title, &center_aligned_style, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// void CalendarUI::setCurrentEvent(std::string title) { lv_label_set_text(title, title.c_str()); }


void CalendarUI::tick() {
    events->tick();

    auto now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::seconds>(now - last_poll).count() < 10) {
        return;
    }

    last_poll = std::chrono::system_clock::now();

    auto current = events->currentEvent();
    auto upcoming = events->upcomingEvent();

    std::string nowS = events->nowStr();

    std::cout << " curr: " << current << " upcomin: " << upcoming << " now: " << nowS <<std::endl;

    lv_label_set_text(this->time,nowS.c_str());

    lv_obj_add_flag(freedom_image, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(headphones_image, LV_OBJ_FLAG_HIDDEN);

    if (current) {

        auto title = current->title();
        if (upcoming) {
            title += "\n";
            title += "then @ ";
            title += upcoming->startHHMM();
            title += ": ";
            title += upcoming->title();
        }
        lv_label_set_text(this->title, title.c_str());
        lv_obj_set_y(this->title, 50);

        lv_label_set_text(this->duration, current->duration().c_str());

    } else if (upcoming) {
        if (upcoming->isNearlyActive()) {
            lv_obj_set_y(title, 60);
            lv_label_set_text(this->title, upcoming->title().c_str());
        } else {
            lv_obj_set_y(title, 120);
            lv_obj_clear_flag(headphones_image, LV_OBJ_FLAG_HIDDEN);

            auto title = upcoming->startHHMM();
            std::cout << "UPCOM NEAR: " << title << std::endl;
            title += ": ";
            title += upcoming->title();
            lv_label_set_text(this->title, title.c_str());

        std::cout << " upcom tit: " << title << std::endl;
        }

        lv_label_set_text(duration, upcoming->duration().c_str());
    } else {
        lv_obj_clear_flag(freedom_image, LV_OBJ_FLAG_HIDDEN);

    }

    lv_refr_now(NULL);
}
