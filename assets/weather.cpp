#include "weather.h"

//#include "font.h"
#include "meteocon.h"
// #include "src/core/lv_obj.h"
// #include "src/core/lv_obj_pos.h"
// #include "src/misc/lv_area.h"
#include "src/extra/widgets/chart/lv_chart.h"
#include "src/misc/lv_color.h"
#include "src/widgets/lv_label.h"
#include <stdio.h>
#include <fmt/format.h>
#include <iostream>
#include <unordered_map>

#include "esp_log.h"

static const char *TAG = "weather";


 WeatherUI::WeatherUI(WeatherAPI *a): api(a) { }


 void WeatherUI::tick() {
    if (!api->tick()) {
        return;
    }


    ESP_LOGI(TAG, "polling for Weather");

    lv_label_set_text(screen_label_temp, api->current_temp_degrees().c_str());
    lv_label_set_text(screen_label_temp_point, api->current_temp_decimal().c_str());

    lv_label_set_text(this->screen_label_forcast_desc, api->current_conditions().c_str());
    auto meteocon = api->current_meteocon();
    if (meteocon) {
        lv_img_set_src(this->screen_img_meteocon, meteocon);
        lv_obj_clear_flag(this->screen_img_meteocon, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(this->screen_img_meteocon, LV_OBJ_FLAG_HIDDEN);
    }
    auto feels = fmt::format("Feels like {:0.0f}°", api->forecast.current.feels_like);
    lv_label_set_text(this->screen_label_feels, feels.c_str());


    auto today = api->forcastForDay(0);

    lv_label_set_text(this->screen_label_temp_high, fmt::format("H: {:.0f}°", today.temp.max).c_str());
    lv_label_set_text(this->screen_label_temp_low, fmt::format("L: {:0.0f}°", today.temp.min).c_str());

    lv_label_set_text(this->screen_label_pop, fmt::format("{}",today.pop).c_str());
    lv_label_set_text(this->screen_label_humidity, fmt::format("{}",today.humidity).c_str());
    lv_label_set_text(this->screen_label_uvi, fmt::format("{:0.1f}",today.uvi).c_str());
    lv_label_set_text(this->screen_label_pressure, fmt::format("{}",today.pressure).c_str());

    lv_label_set_text(this->near_forecast, today.summary.c_str());

    for (int i = 0; i < MAX_DAYS; i++) {
      this->daily_forecasts[i]->update(api->forecast.daily[i+1]);
    }
}


void WeatherUI::setup(lv_obj_t *parent) {
    auto width = lv_obj_get_width(parent);
    auto height = lv_obj_get_height(parent);
    height = height * 0.5;
    // Write codes screen
    this->screen = lv_obj_create(parent);
    lv_obj_set_pos(this->screen, 0, height);
    lv_obj_set_size(this->screen, width, height);
    lv_obj_set_scrollbar_mode(this->screen, LV_SCROLLBAR_MODE_OFF);

    static lv_style_t style_lg_text;
    if (style_lg_text.prop_cnt > 1)
      lv_style_reset(&style_lg_text);
    else
      lv_style_init(&style_lg_text);
    lv_style_set_text_font(&style_lg_text, &font_lato_18); // lv_font_montserrat_40);

    static lv_style_t style_right_align_text;
    if (style_right_align_text.prop_cnt > 1)
      lv_style_reset(&style_right_align_text);
    else
      lv_style_init(&style_right_align_text);
    lv_style_set_text_align(&style_right_align_text, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_text_font(&style_right_align_text, &lv_font_montserrat_14);

    static lv_style_t style_center_align_text;
    if (style_center_align_text.prop_cnt > 1)
      lv_style_reset(&style_center_align_text);
    else
      lv_style_init(&style_center_align_text);
    lv_style_set_text_align(&style_center_align_text, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_font(&style_center_align_text, &lv_font_montserrat_14);

    static lv_style_t style_icon_text;
    if (style_icon_text.prop_cnt > 1)
      lv_style_reset(&style_icon_text);
    else
      lv_style_init(&style_icon_text);
    lv_style_set_text_font(&style_icon_text, &font_icon_14);


    static lv_style_t screen_style;
    lv_style_set_radius(&screen_style, 0);
    lv_style_set_pad_all(&screen_style, 0);
    lv_style_set_border_width(&screen_style, 0);
    lv_obj_add_style(this->screen, &screen_style, LV_PART_MAIN);
    lv_style_set_bg_color(&screen_style, lv_color_make(0, 0, 0));
    lv_style_set_text_color(&screen_style, lv_color_make(0xff, 0xff, 0xff));


    this->near_forecast = lv_label_create(this->screen);
    lv_obj_set_pos(this->near_forecast, 140, 10);
    lv_obj_set_size(this->near_forecast, width-130, 20);
    lv_label_set_text(this->near_forecast, "");

    lv_obj_add_style(this->near_forecast, &style_lg_text, LV_PART_MAIN | LV_STATE_DEFAULT);


    this->screen_label_temp = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_temp, 55, 13);
    lv_obj_set_size(this->screen_label_temp, 55, 30);
    lv_label_set_text(this->screen_label_temp, "");


    static lv_style_t style_screen_label_temp;
    if (style_screen_label_temp.prop_cnt > 1)
      lv_style_reset(&style_screen_label_temp);
    else
      lv_style_init(&style_screen_label_temp);
    lv_style_set_radius(&style_screen_label_temp, 0);
    lv_style_set_text_font(&style_screen_label_temp, &font_lato_24);
    lv_style_set_text_align(&style_screen_label_temp, LV_TEXT_ALIGN_RIGHT);
    lv_obj_add_style(this->screen_label_temp, &style_screen_label_temp, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_label_temp_point
    this->screen_label_temp_point = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_temp_point, 110, 25);
    lv_obj_set_size(this->screen_label_temp_point, 28, 15);
    lv_label_set_text(this->screen_label_temp_point, "");
    lv_obj_add_style(this->screen_label_temp_point, &style_lg_text, LV_PART_MAIN | LV_STATE_DEFAULT);



    this->temp_type = lv_label_create(this->screen);
    lv_obj_set_pos(this->temp_type, 110, 8);
    lv_obj_set_size(this->temp_type, 27, 15);
    lv_label_set_text(this->temp_type, "°F");
    lv_label_set_long_mode(this->temp_type, LV_LABEL_LONG_WRAP);


    this->screen_img_meteocon = lv_img_create(this->screen);
    lv_obj_set_pos(this->screen_img_meteocon, 10, 3);
    //lv_img_set_size_mode(this->screen_img_meteocon, LV_SIZE_CONTENT);
    lv_img_set_src(this->screen_img_meteocon, &asset_clear_sky_day);

    this->screen_label_forcast_desc = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_forcast_desc, 10, 50);
    lv_obj_set_size(this->screen_label_forcast_desc, 140, 15);
    lv_label_set_text(this->screen_label_forcast_desc, "");
    lv_label_set_long_mode(this->screen_label_forcast_desc, LV_LABEL_LONG_DOT);



    this->screen_label_feels = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_feels, 10, 70);
    lv_obj_set_size(this->screen_label_feels, 140, 15);
    lv_label_set_text(this->screen_label_feels, "");
    lv_label_set_long_mode(this->screen_label_feels, LV_LABEL_LONG_DOT);



    this->screen_label_temp_high = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_temp_high, 10, 90);
    lv_obj_set_size(this->screen_label_temp_high, 50, 12);
    lv_obj_set_scrollbar_mode(this->screen_label_temp_high,
                              LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->screen_label_temp_high, "");

    this->screen_label_temp_low = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_temp_low, 75, 90);
    lv_obj_set_size(this->screen_label_temp_low, 50, 12);
    lv_obj_set_scrollbar_mode(this->screen_label_temp_low, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->screen_label_temp_low, "");
    lv_label_set_long_mode(this->screen_label_temp_low, LV_LABEL_LONG_WRAP);
    lv_obj_add_style(this->screen_label_temp_low, &style_right_align_text, LV_PART_MAIN);


    this->forecast_conditions_icon = lv_label_create(this->screen);
    lv_obj_set_pos(this->forecast_conditions_icon, 10, 108);
    lv_obj_set_size(this->forecast_conditions_icon, 15, 15);
    lv_obj_add_style(this->forecast_conditions_icon, &style_icon_text, LV_PART_MAIN);
    lv_label_set_text(this->forecast_conditions_icon, FA_SYMBOL_UMBRELLA);

    this->screen_label_pop = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_pop, 30, 112);
    lv_obj_set_size(this->screen_label_pop, 25, 15);
    lv_label_set_text(this->screen_label_pop, "");
    lv_obj_add_style(this->screen_label_pop, &style_right_align_text, LV_PART_MAIN);



    this->humidity_icon = lv_label_create(this->screen);
    lv_obj_set_pos(this->humidity_icon, 75, 108);
    lv_obj_set_size(this->humidity_icon, 15, 15);
    lv_obj_set_scrollbar_mode(this->humidity_icon, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(this->humidity_icon, FA_SYMBOL_DROPLET);

    this->screen_label_humidity = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_humidity, 85, 110);
    lv_obj_set_size(this->screen_label_humidity, 40, 15);
    lv_label_set_text(this->screen_label_humidity, "");
    lv_obj_add_style(this->screen_label_humidity, &style_right_align_text, LV_PART_MAIN);



    this->uvi_icon = lv_label_create(this->screen);
    lv_obj_set_pos(this->uvi_icon, 10, 128);
    lv_obj_set_size(this->uvi_icon, 15, 15);
    lv_obj_add_style(this->uvi_icon, &style_icon_text, LV_STATE_DEFAULT);
    lv_label_set_text(this->uvi_icon, FA_SYMBOL_SUN);

    this->screen_label_uvi = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_uvi, 20, 130);
    lv_obj_set_size(this->screen_label_uvi, 35, 15);
    lv_label_set_text(this->screen_label_uvi, "9");
    lv_obj_add_style(this->screen_label_uvi, &style_right_align_text, LV_PART_MAIN);



    this->pressure_icon = lv_label_create(this->screen);
    lv_obj_set_pos(this->pressure_icon, 73, 128);
    lv_obj_set_size(this->pressure_icon, 15, 15);
    lv_obj_add_style(this->pressure_icon, &style_icon_text, LV_PART_MAIN);
    lv_label_set_text(this->pressure_icon, FA_SYMBOL_PRESSURE);

    // Write codes screen_label_pressure
    this->screen_label_pressure = lv_label_create(this->screen);
    lv_obj_set_pos(this->screen_label_pressure, 80, 130);
    lv_obj_set_size(this->screen_label_pressure, 45, 15);
    lv_label_set_text(this->screen_label_pressure, "");
    lv_obj_add_style(this->screen_label_pressure, &style_right_align_text, LV_PART_MAIN);


    // Write codes daily_forecast_line
    this->daily_forecast_line = lv_line_create(this->screen);
    lv_obj_set_pos(this->daily_forecast_line, 130, 45);
    // lv_obj_set_size(this->daily_forecast_line, 230, 1);
    lv_obj_set_scrollbar_mode(this->daily_forecast_line, LV_SCROLLBAR_MODE_OFF);

    static lv_point_t daily_forecast_line_points[]
        = { { 0, 100 },
            { 0, 0 },
            {430, 0}
    };
    lv_line_set_points(this->daily_forecast_line, daily_forecast_line_points, 3);

    static lv_style_t style_line;
    if (style_line.prop_cnt > 1)
      lv_style_reset(&style_line);
    else
      lv_style_init(&style_line);
    lv_style_set_line_color(&style_line, lv_color_make(0x43, 0x4d, 0x46));
    lv_style_set_line_width(&style_line, 1);

    lv_obj_add_style(this->daily_forecast_line, &style_line, LV_PART_MAIN);




    for (int i = 0; i < MAX_DAYS; i++) {
      this->daily_forecasts.push_back(new Meteocon(this->screen, &lv_font_montserrat_14, 135 + (i*55), 55));
    }

//     static lv_style_t style_chart;
//     lv_style_init(&style_chart);
//     lv_style_set_pad_top(&style_chart, 0);
//     lv_style_set_border_opa(&style_chart, LV_OPA_TRANSP);
//     lv_style_set_border_width(&style_chart, 0);

//     lv_obj_t * chart;
//     chart = lv_chart_create(this->screen);
//     lv_obj_set_pos(chart, 130, 00);
//     lv_obj_set_size(chart, 200, 150);
//     lv_obj_set_style_pad_column(chart, 2, 0);
//     lv_chart_set_point_count(chart, 5);
//     lv_chart_set_type(chart, LV_CHART_TYPE_BAR);
//     lv_chart_set_div_line_count(chart, 0, 0);
//   //  lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, -10, 100);

// //    lv_obj_set_style_bg_opa(chart, LV_OPA_TRANSP, LV_PART_MAIN);

//     lv_obj_add_style(chart, &style_chart, LV_PART_MAIN);


//     /*Add two data series*/
//     lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_color_make(0x43, 0x4d, 0x46),LV_CHART_AXIS_PRIMARY_Y);


//     /*Set the next points on 'ser1'*/
//     // lv_chart_set_next_value(chart, ser1, 80);
//     // lv_chart_set_next_value(chart, ser1, 50);
//     lv_chart_set_next_value(chart, ser1, 1);
//     lv_chart_set_next_value(chart, ser1, 30);
//    lv_chart_set_next_value(chart, ser1, 100);

    // lv_chart_set_next(chart, ser1, 10);
    // lv_chart_set_next(chart, ser1, 10);

    // static lv_point_t line_points[] = { {5, 0}, {5, 15} };

    // /*Create style*/
    // static lv_style_t style_bar_line;
    // lv_style_init(&style_bar_line);
    // lv_style_set_line_width(&style_bar_line, 5);
    // lv_style_set_line_color(&style_bar_line, lv_palette_main(LV_PALETTE_BLUE));
    // lv_style_set_line_rounded(&style_bar_line, false);

    // lv_obj_t * line1;
    // line1 = lv_line_create(this->screen);

    // lv_line_set_points(line1, line_points, 2);
    // lv_obj_add_style(line1, &style_bar_line, 0);

    // lv_obj_set_pos(line1, 140, 30);

    // lv_obj_center(line1);




    static lv_style_t style_bar;
    if (style_bar.prop_cnt > 1)
      lv_style_reset(&style_bar);
    else
      lv_style_init(&style_bar);

      //lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_line_color(&style_bar, lv_color_make(98, 191, 233));
    lv_style_set_line_width(&style_bar, 5);

    int i = 0;
   // for (int i = 0; i < 60; i++) {
        auto line = lv_line_create(this->screen);

        std::cout << line << std::endl;

        lv_coord_t xpos = 130 + (i * 5);

        lv_obj_set_pos(line, xpos, 95);
        lv_obj_set_size(line, 200, 200);

   //      lv_obj_set_scrollbar_mode(line, LV_SCROLLBAR_MODE_OFF);

      //  lv_point_t line_points[] = { {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };


        // lv_point_t line_points[] = {
        //      { 0, 30 },
        //      { 0, 0 },
        // };

      //  lv_line_set_points(line, line_points, 5);

        lv_obj_add_style(line, &style_bar, LV_PART_MAIN);

        this->lines.push_back(line);
    // }




}
