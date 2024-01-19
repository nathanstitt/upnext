#pragma once

#include "upnext_config.h"
#include "lvgl.h"
#include <string>
#include "json.hpp"

using json = nlohmann::json;


LV_IMG_DECLARE(asset_clear_sky_day);
LV_IMG_DECLARE(asset_clear_sky_night);
LV_IMG_DECLARE(asset_few_clouds_day);
LV_IMG_DECLARE(asset_few_clouds_night);
LV_IMG_DECLARE(asset_scattered_clouds);
LV_IMG_DECLARE(asset_broken_clouds_day);
LV_IMG_DECLARE(asset_broken_clouds_night);
LV_IMG_DECLARE(asset_shower_rain_day);
LV_IMG_DECLARE(asset_shower_rain_night);
LV_IMG_DECLARE(asset_rain);
LV_IMG_DECLARE(asset_thunderstorm);
LV_IMG_DECLARE(asset_snow );
LV_IMG_DECLARE(asset_mist);


namespace OW {

    struct CurrentRain {
        float hr = 0;

    };

    void to_json(json& j, const CurrentRain& cr);

    void from_json(const json& j, CurrentRain& cr);

    struct WeatherCondition {
        int32_t id;
        std::string description;
        std::string icon;
        std::string main;

        const lv_img_dsc_t *meteocon() const;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(WeatherCondition, description, icon, id, main)
    };

    struct WeatherAlert {
        std::string sender_name;
        std::string event;
        uint32_t    start = 0;
        uint32_t    end   = 0;
        std::string description;
        std::vector<std::string> tags;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(WeatherAlert, sender_name, event, start, end, description, tags)
    };


    struct Current {

        uint8_t clouds = 0;
        float   dew_point = 0;
        uint32_t dt = 0;
        float feels_like = 0;
        uint8_t humidity = 0;
        float pressure = 0;
        CurrentRain rain;
        uint32_t sunrise = 0;
        uint32_t sunset = 0;
        float temp = 0;
        float uvi = 0;
        uint32_t visibility = 0;
        std::vector<WeatherCondition> weather;
        WeatherCondition condition() const;
        uint16_t wind_deg = 0;
        float wind_speed = 0;
        float wind_gust = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Current,
                                                    clouds,
                                                    dew_point,
                                                    dt,
                                                    feels_like,
                                                    humidity,
                                                    pressure,
                                                    rain,
                                                    sunrise,
                                                    sunset,
                                                    temp,
                                                    uvi,
                                                    visibility,
                                                    weather,
                                                    wind_deg,
                                                    wind_speed,
                                                    wind_gust
                                                    )

    };

    struct DailyTemp {
        float morn = 0;
        float day = 0;
        float eve = 0;
        float night = 0;
        float min = 0;
        float max = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(DailyTemp, morn, day, eve, night, min, max )
    };

    struct DailyFeelsLike {
        float morn = 0;
        float day = 0;
        float eve = 0;
        float night = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(DailyFeelsLike, morn, day, eve, night)
    };

    struct Minute {
        std::time_t dt;
        uint32_t precipitation;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Minute, dt, precipitation);
    };

    struct Daily {
        std::time_t dt;
        uint32_t sunrise = 0;
        uint32_t sunset = 0;
        uint32_t moonrise = 0;
        uint32_t moonset = 0;
        float moon_phase;
        std::string summary;
        DailyTemp temp;
        DailyFeelsLike feels_like;

        float pressure = 0;
        uint8_t humidity = 0;
        float dew_point = 0;
        float wind_speed = 0;
        float wind_gust = 0;
        uint16_t wind_deg = 0;
        uint8_t clouds = 0;
        float    uvi        = 0;
        float pop = 0;
        float rain = 0;
        float    snow       = 0;

        std::vector<WeatherCondition> weather;

        WeatherCondition condition() const;

        const std::string precip() const;
        const std::string highLow() const;

        std::vector<WeatherAlert> alerts;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Daily,
                                                    dt,
                                                    sunrise,
                                                    sunset,
                                                    moonrise,
                                                    moonset,
                                                    moon_phase,
                                                    summary,
                                                    temp,
                                                    feels_like,
                                                    pressure,
                                                    humidity,
                                                    dew_point,
                                                    wind_speed,
                                                    wind_gust,
                                                    wind_deg, clouds, uvi, pop, rain, snow, weather)
    };


    struct Hourly {

        // hourly
        uint32_t dt = 0;
        float temp = 0;
        float feels_like = 0;
        float pressure = 0;
        uint8_t humidity = 0;
        float    dew_point  = 0;
        uint32_t uvi = 0;
        uint8_t  clouds     = 0;
        uint8_t visibility = 0;
        float wind_speed = 0;
        float wind_gust = 0;
        uint16_t wind_deg = 0;
        float rain = 0;
        float snow = 0;

        std::vector<WeatherCondition> weather;


        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Hourly,
                                                    dt,
                                                    temp,
                                                    feels_like,
                                                    pressure,
                                                    humidity,
                                                    dew_point,
                                                    uvi,
                                                    clouds,
                                                    visibility,
                                                    wind_speed,
                                                    wind_deg,
                                                    wind_gust,
                                                    weather);
    };

    struct Forecast {
        float lat = 0;
        float lon = 0;
        std::string timezone;
        uint32_t timezone_offset = 0;
        Current     current;
        std::vector<Hourly> hourly;
        std::vector<Daily> daily;
        std::vector<Minute> minutely;
        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Forecast, lat, lon, timezone, timezone_offset, current, hourly, daily, minutely);
    };

};
