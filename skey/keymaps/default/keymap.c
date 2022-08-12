
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>

// I can create a custom keycode:
//enum my_keycodes {
//  FOO = SAFE_RANGE,
//  BAR = SAFE_RANGE
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*        Layer 0
    ┌───────┬───────┐
    │   `   │  LNG1 │
    ├───────┼───────┤
    │ Alt+4 │ Alt+5 │
    ├───────┼───────┤
    │ Alt+7 │ Alt+6 │
    └───────┴───────┘
  
          Layer 1
    ┌───────┬───────┐
    │       │       │
    ├───────┼───────┤
    │QK_BOOT│       │
    ├───────┼───────┤
    │       │       │
    └───────┴───────┘  
  */

	[0] = LAYOUT(
		PB_1, LT(1, KC_LNG1), 
    LALT(KC_P4), LALT(KC_P5),
		LALT(KC_P7), LALT(KC_P6)
	),
	[1] = LAYOUT(
        _______, _______, 
		    QK_BOOT, _______,
        _______, _______
    )
};
// LALT(LCTL(KC_DEL))

// LEFT_SHIFT + KC_F$number works!
// LEFT_CTRL + KC_$letter works!

// KC_MPLY (play/stop) = It works with spotify

// 0xA5 is a Special Key (https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md#special-keys)
// 0x3E = F5
// 0x8d = KEY_UNKNOWN

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PB_1:
      if (record->event.pressed) {
        SEND_STRING("`");
//        register_code(KC_F24);
      } else {
            // when keycode QMKBEST is released
      }
      return false;
      break;
  }
  return true;
};

// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
// https://jayliu50.github.io/qmk-cheatsheet/
// https://github.com/qmk/qmk_firmware/blob/master/docs/configurator_default_keymaps.md

// https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2
// http://www.curlap.com/support/developers/curl/docs/rte/latest/en/docs/en/api-ref/Keycode.html