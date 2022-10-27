#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xDB30
#define PRODUCT_ID      0x6080
#define DEVICE_VER      0x0010
#define MANUFACTURER    BSD
#define PRODUCT         keyboard
#define DESCRIPTION     Keyboard

//#undef TAPPING_TERM
//#define TAPPING_TERM 250
//#define ONESHOT_TIMEOUT 500
//#define ONESHOT_TAP_TOGGLE 3

//#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX, UC_MAC

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/* key matrix pins */
#define DIRECT_PINS {   \
    { B3, B3, B3 }, \
    { F7, B6, B2 }, \
    { B5, B1, D7 }, \
    { B4, E6, C6 }  \
}

#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5