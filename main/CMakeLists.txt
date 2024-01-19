file(GLOB upnext_SRC
     "*.cpp"
     "*.c"
)

file(GLOB_RECURSE ui_SRC "ui" "*.c")
file(GLOB_RECURSE assets_SRC "assets" "*.c")


idf_component_register(
    SRCS ${upnext_SRC} ${ui_SRC} ${assets_SRC}
    INCLUDE_DIRS "../include"
    REQUIRES LovyanGFX lwip esp_wifi vfs fmt lvgl esp_http_client)

add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)

set(COMPONENT_ADD_INCLUDEDIRS "../include")


# idf_component_register( SRCS "main.c" ${LV_UI_SOURCES} INCLUDE_DIRS "." "ui" )


# add_subdirectory(ui)
