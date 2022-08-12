
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		0xA5, LT(1,KC_A), 
		KC_B, KC_C, 
		KC_D, KC_E
	),
	[1] = LAYOUT(
        _______, _______, 
		QK_BOOT, _______,
        _______, _______
    )
};

// 0xA5 is a Special Key (https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md#special-keys)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case 0xA5:
      if (record->event.pressed) {
        SEND_STRING("`");
      } else {
            // when keycode QMKBEST is released
      }
      return false;
      break;
  }
  return true;
};