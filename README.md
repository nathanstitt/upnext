# UPNEXT

## Introduction

This project runs on an ESP32S3 module with a 3.5inch 480x320 display using the ILI9488 chip. Code was tested on a [Elecrow 3.5inch Terminal](https://www.elecrow.com/esp-terminal-with-esp32-3-5-inch-parallel-480x320-tft-capacitive-touch-display-rgb-by-chip-ili9488.html), but could be easily adapted to other displays.

The code reads the current day's calendar events from Google Calendar, the current weather and a 3-day forecast from [OpenWeatherMap](https://openweathermap.org/api/one-call-3). It's a perfect addition to any desk or home environment, providing real-time updates at a glance.

## Features
- **Current Day's Calendar Events:** Displays your scheduled events for the day.
- **Current Weather Information:** Shows real-time weather conditions and 60 minute rain intensity.
- **3-Day Weather Forecast:** Provides a forecast for the next three days.

## Hardware/Software Requirements
- ESP32S3 Module
- ILI9488 LED Display
- ESP IDF

## Installation
1. **Setting up the ESP32 with Espressif:** 
   - Follow [this guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) to setup your environment.
3. **Configuration:**
   - Copy the `include/upnext_config_sample.h` file to `include/upnext_config.h`, edit and add your WiFi credentials, API keys for OpenWeather.
   - Install the [google calendar script](assets/upnext-google-script.gs) into a new project in the [Google Script Console](https://script.google.com/), deploy it as a WebApp with access granted to everyone and copy the deployment ID into the CALENDAR_DEPLOYMENT_ID for the script into `include/upnext_config.h`

## Usage
- **Flashing the ESP32:**
  - Connect your ESP32 to your computer.
  - run `idf.py build`
  - `idf.py flash` 
- **Operation:**
  - The device automatically connects to WiFi.
  - Fetches and displays the calendar events and weather data.

## Contributing

If you fork the project and modify it to better suite your purposes, please let me know!

Happy Building!
