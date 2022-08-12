
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
    ┌────┬────┐
    │    │    │
    ├────┼────┤
    │    │    │
    ├────┼────┤
    │    │    │
    └────┴────┘
  
  */

	[0] = LAYOUT(
		0xA5, LT(1,KC_F19), 
		KC_KB_MUTE, BAR, 
		KC_KB_VOLUME_UP, FOO
//		KC_F20, KC_F21, 
//		KC_F22, KC_F23
	),
	[1] = LAYOUT(
        _______, _______, 
		QK_BOOT, _______,
        _______, _______
    )
};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}

// KC_MPLY (play/stop) = It works with spotify

// 0xA5 is a Special Key (https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md#special-keys)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case 0xA5:
      if (record->event.pressed) {
//        SEND_STRING("`");
        register_code(KC_F24);
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