#include "meteocon.h"
#include "weather.h"
#include <fmt/format.h>

void Meteocon::update(const OW::Daily& forecast) {
    char dt[10];
    std::strftime(dt, sizeof(dt), "%e %b", std::localtime(&forecast.dt));
    lv_label_set_text(this->date, dt);
    auto weather = forecast.weather.begin();
    if (weather != forecast.weather.end()) {
        auto img = weather->meteocon();
        if (img) {
            lv_img_set_src(this->img, img);
            lv_obj_clear_flag(this->img, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(this->img, LV_OBJ_FLAG_HIDDEN);
        }
    }
    auto temp = fmt::format("{:0.0f} {:0.0f}", forecast.temp.min, forecast.temp.max);
    lv_label_set_text(this->hilo, temp.c_str());


    auto pop = fmt::format("{:0.0f}%", forecast.pop * 100);
    lv_label_set_text(this->precip, pop.c_str());
}

Meteocon::Meteocon(lv_obj_t *parent, const lv_font_t *font, lv_coord_t _x,
                   lv_coord_t _y)
    : x(_x), y(_y) {

    this->screen = lv_obj_create(parent);

    static lv_style_t screen_style;
    lv_style_set_radius(&screen_style, 0);
    lv_style_set_pad_all(&screen_style, 0);
    lv_style_set_border_width(&screen_style, 0);
    lv_style_set_bg_color(&screen_style, lv_color_make(0, 0, 0));
    lv_style_set_text_color(&screen_style, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_align(&screen_style, LV_TEXT_ALIGN_CENTER);

    lv_obj_add_style(this->screen, &screen_style, LV_PART_MAIN);


    lv_obj_set_pos(this->screen, x, y);

    lv_obj_set_size(this->screen, 55, 140);
    lv_obj_set_scrollbar_mode(this->screen, LV_SCROLLBAR_MODE_OFF);

    // Write codes screen_label_forcast_date1
    this->date = lv_label_create(this->screen);
    lv_obj_set_pos(this->date, 0, 0);
    lv_obj_set_size(this->date, 55, 13);
    lv_obj_set_scrollbar_mode(this->date, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->date, "");
    lv_label_set_long_mode(this->date, LV_LABEL_LONG_WRAP);

    // Write style state: LV_STATE_DEFAULT for
    // style_date_main_main_default
    static lv_style_t style_text;
    if (style_text.prop_cnt > 1)
        lv_style_reset(&style_text);
    else
        lv_style_init(&style_text);

    lv_style_set_text_font(&style_text, font);

    lv_obj_add_style(this->screen, &style_text, LV_PART_MAIN);
    // lv_obj_add_style(this->date, &style_text,
    //                  LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_img_meteocon1
    this->img = lv_img_create(this->screen);
    lv_obj_set_pos(this->img, 10, 18);

    static lv_style_t style_img;
    if (style_img.prop_cnt > 1)
        lv_style_reset(&style_img);
    else
        lv_style_init(&style_img);
    lv_style_set_img_recolor(&style_img,
                             lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_img_recolor_opa(&style_img, 0);
    lv_style_set_img_opa(&style_img, 255);
    lv_obj_add_style(this->img, &style_img,
                     LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(this->img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_size_mode(this->img, LV_SIZE_CONTENT);

    // lv_img_set_pivot(this->img, 0, 0);
    // lv_img_set_angle(this->img, 0);

    // Write codes hilo
    this->hilo = lv_label_create(this->screen);
    lv_obj_set_pos(this->hilo, 0, 68);
    lv_obj_set_size(this->hilo, 55, 13);

    lv_obj_set_scrollbar_mode(this->hilo, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->hilo, "");
    lv_label_set_long_mode(this->hilo, LV_LABEL_LONG_WRAP);

    lv_obj_add_style(this->hilo, &style_text,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    this->precip = lv_label_create(this->screen);
    lv_obj_set_pos(this->precip, 0, 83);
    lv_obj_set_size(this->precip, 55, 13);
    lv_obj_set_scrollbar_mode(this->precip, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->precip, "");
    lv_label_set_long_mode(this->precip, LV_LABEL_LONG_WRAP);

    lv_obj_add_style(this->precip, &style_text,
                     LV_PART_MAIN | LV_STATE_DEFAULT);


    // Write style state: LV_STATE_DEFAULT for
    // // style_precip_main_main_default
    // static lv_style_t style_precip_main_main_default;
    // if (style_precip_main_main_default.prop_cnt > 1)
    //   lv_style_reset(&style_precip_main_main_default);
    // else
    //   lv_style_init(&style_precip_main_main_default);
    // lv_style_set_radius(&style_precip_main_main_default, 0);
    // lv_style_set_bg_color(&style_precip_main_main_default,
    //                       lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_bg_grad_color(&style_precip_main_main_default,
    //                            lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_bg_grad_dir(&style_precip_main_main_default, LV_GRAD_DIR_NONE);
    // lv_style_set_bg_opa(&style_precip_main_main_default, 0);
    // lv_style_set_shadow_width(&style_precip_main_main_default, 0);
    // lv_style_set_shadow_color(&style_precip_main_main_default,
    //                           lv_color_make(0x21, 0x95, 0xf6));
    // lv_style_set_shadow_opa(&style_precip_main_main_default, 255);
    // lv_style_set_shadow_spread(&style_precip_main_main_default, 0);
    // lv_style_set_shadow_ofs_x(&style_precip_main_main_default, 0);
    // lv_style_set_shadow_ofs_y(&style_precip_main_main_default, 0);
    // lv_style_set_text_color(&style_precip_main_main_default,
    //                         lv_color_make(0xff, 0xff, 0xff));
    // lv_style_set_text_font(&style_precip_main_main_default, font);
    // lv_style_set_text_letter_space(&style_precip_main_main_default, 2);
    // lv_style_set_text_line_space(&style_precip_main_main_default, 0);
    // lv_style_set_text_align(&style_precip_main_main_default, LV_TEXT_ALIGN_LEFT);
    // lv_style_set_pad_left(&style_precip_main_main_default, 0);
    // lv_style_set_pad_right(&style_precip_main_main_default, 0);
    // lv_style_set_pad_top(&style_precip_main_main_default, 0);
    // lv_style_set_pad_bottom(&style_precip_main_main_default, 0);
    // lv_obj_add_style(this->precip, &style_precip_main_main_default,
    //                  LV_PART_MAIN | LV_STATE_DEFAULT);
}
