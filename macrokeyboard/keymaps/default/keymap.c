#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		0xA5, KC_F13, KC_F14),
//       Pin9    Pin8    Pin7`
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
