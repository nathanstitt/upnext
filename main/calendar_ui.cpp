#include <functional>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "fmt/format.h"
#include "lvgl.h"
#include "calendar_ui.h"
#include "calendar.h"
#include "upnext_config.h"
#include "esp_log.h"
#include "ui/ui.h"

static const char *TAG = "cal";


using json = nlohmann::json;


LV_IMG_DECLARE(asset_activity_meeting);
LV_IMG_DECLARE(asset_activity_cheers);
LV_IMG_DECLARE(asset_activity_headphones);


CalendarUI::CalendarUI(Network *n)
    : network(n),
      last_poll(std::chrono::steady_clock::now() - std::chrono::hours(1)),
      last_update(last_poll) {

}


std::time_t CalendarUI::now() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return now_c;
}


std::string CalendarUI::nowStr() {
    auto now = std::chrono::system_clock::now();
    std::time_t nw = std::chrono::system_clock::to_time_t(now);
    return Cal::timeToStr(nw);
}


void CalendarUI::tick() {
    auto now = std::chrono::steady_clock::now();

    if (std::chrono::duration_cast<std::chrono::seconds>(now - last_update)
            .count() > 10) {
        updateUI();
        last_update = now;
    }

    if (!is_fetching && std::chrono::duration_cast<std::chrono::minutes>(now - last_poll).count() > 5) {

        ESP_LOGI(TAG, "Polling for calendar");

        auto onDone = [this](bool success, const json &j) -> void {
            ESP_LOGI(TAG, "Fetched Calendar: %s", success ? "success" : "failed");
            this->is_fetching = false;
          if (success) {
              this->updateEvents(j);
              this->last_poll = std::chrono::steady_clock::now();
          }
        };
        is_fetching = true;
        network->fetchCalendarEvents(onDone);
    }
}

void CalendarUI::updateEvents(const json &j) {

    this->calendar = j.template get<Cal::Calendar>();
    auto events = &this->calendar.events;

    events->erase(
        std::remove_if(events->begin(), events->end(),
                       [](const Cal::Event &ev) { return !ev.occursToday(); }),
        events->end()
    );

    std::sort(events->begin(), events->end(),
              [](auto &a, auto &b) {
                return a.startTime() < b.startTime();
              });


    ESP_LOGI(TAG, "Found %d Calendar Events", events->size());
}

void CalendarUI::updateUI() {
    lv_label_set_text(ui_curtime, nowStr().c_str());

    auto const current = this->calendar.currentEvent();
    auto const upcoming = this->calendar.upcomingEvent();


    std::stringstream title;
    std::stringstream duration;

    if (current) {
        title << current->title;

        lv_img_set_src(ui_currentActivity, &asset_activity_meeting);
        if (upcoming) {
            title << "\nthen @ " << upcoming->startHHMM() << ": " << upcoming->title;
        }

        duration << current->duration();

    } else if (upcoming) {
        if (upcoming->isNearlyActive()) {
            lv_label_set_text(ui_eventTitle, upcoming->title.c_str());
            lv_img_set_src(ui_currentActivity, &asset_activity_meeting);
            title << "In " << upcoming->minutesFromNow() << " mins: ";
        } else {
            lv_img_set_src(ui_currentActivity, &asset_activity_headphones);
            title << upcoming->startHHMM() << ": ";
            duration << upcoming->duration();
        }
        title << upcoming->title;
    } else {
        lv_img_set_src(ui_currentActivity, &asset_activity_cheers);
        title << "No" << (this->calendar.events.empty() ? "" : " more") << " events today";
        duration << "";
    }
    lv_label_set_text(ui_eventTitle, title.str().c_str());
    lv_label_set_text(ui_duration, duration.str().c_str());

    lv_refr_now(NULL);

}
