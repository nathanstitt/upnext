SET(SOURCES screens/ui_screen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_lato14.c
    fonts/ui_font_lato22.c)

add_library(ui ${SOURCES})
