
#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 2

/* key matrix pins */
#define DIRECT_PINS {   \
    { B5, B4 }, \
    { E6, D7 }, \
    { B6, B2 }  \
}

#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5