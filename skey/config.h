// Oled conf
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 0
//#define MANUFACTURER "BSD Keyboards"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/* key matrix pins */
#define DIRECT_PINS {   \
    { D4, B3, F6 }, \
    { F7, B6, B2 }, \
    { B5, B1, D7 }, \
    { B4, E6, C6 }  \
}

#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE