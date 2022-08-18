
#include "config_common.h"
//#undef TAPPING_TERM
//#define TAPPING_TERM 250
//#define ONESHOT_TIMEOUT 500
//#define ONESHOT_TAP_TOGGLE 3
#define OLED_FONT_HEIGHT 3

//#define UNICODE_SELECTED_MODES UC_WINC, UC_LNX, UC_MAC

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* key matrix pins */
#define DIRECT_PINS {   \
    { B5, B4 }, \
    { E6, D7, C6 }, \
    { B6, B2 }  \
}

#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5