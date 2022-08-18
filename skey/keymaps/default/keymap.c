
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>
#include <stdlib.h>
#define OLED_FONT_HEIGHT 3

// Display connection on Arduino Pro Micro
// Display -> Pro Micro
// SDA -> 2 (D1)
// SCK -> 3 (D0)
// VCC -> VCC
// GND -> GND


enum my_keycodes {
  gitstatus = SAFE_RANGE,
  gitdiff,
  gitpush,
  gitpull
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*    Common Layer
    ┌───────┬───────┐
    │   `   │  LNG1 │
    ├───────┼───────┤ ┌───────┐
    │ Alt+4 │ Alt+5 │ │Layers │
    ├───────┼───────┤ └───────┘
    │ Alt+6 │ Alt+7 │
    └───────┴───────┘

      Layers - Used to switch between layers
    ┌─────────┬─────────┐
    │ Media   │         │
    ├─────────┼─────────┤ ┌─────────┐
    │ Quantum │         │ │ Common  │
    ├─────────┼─────────┤ └─────────┘
    │ Git     │         │
    └─────────┴─────────┘  

      Quantum_layer - Used to update the firmware
    ┌───────┬───────┐
    │       │       │
    ├───────┼───────┤ ┌───────┐
    │QK_BOOT│       │ │Layers │
    ├───────┼───────┤ └───────┘
    │       │       │
    └───────┴───────┘  

      Media_layer - Used to control Media
    ┌───────┬───────┐
    │       │ Next  │
    ├───────┼───────┤ ┌───────┐
    │ Mute  │ Prev  │ │Layers │ // Mute Output song | 
    ├───────┼───────┤ └───────┘
    │ Pl/St │       │ // Play and Stop | 
    └───────┴───────┘  

      Git
    ┌───────┬───────┐
    │Status │ Diff  │
    ├───────┼───────┤ ┌───────┐
    │ Push  │ Pull  │ │Layers │
    ├───────┼───────┤ └───────┘
    │       │       │ 
    └───────┴───────┘  
  */

	[0] = LAYOUT(
		BR_ACUT, LT(2, KC_LNG1), 
    LALT(KC_P4), LALT(KC_P5), TO(1),
		LALT(KC_P6), LALT(KC_P7)
	),
	[1] = LAYOUT(
        TO(3), KC_NO, 
        TO(2), KC_NO, TO(0),
        TO(4), KC_NO
    ),
	[2] = LAYOUT(
        KC_NO, KC_NO, 
        QK_BOOT, KC_NO, TO(1),
        KC_NO, KC_EXEC
    ),
	[3] = LAYOUT(
        KC_NO, KC_MNXT,
        KC_MUTE, KC_MPRV, TO(1),
        KC_MPLY, KC_NO
    ),
	[4] = LAYOUT(
        gitstatus, gitdiff,
        gitpush, gitpull, TO(1),
        KC_A, KC_B
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {    
    case BR_ACUT:
      if (record->event.pressed) {
        SEND_STRING("```");
      }
      return false;
      break;
    case gitstatus:
      if (record->event.pressed) {
        SEND_STRING("git status\n");
      }
      return false;
      break;
    case gitdiff:
      if (record->event.pressed) {
        SEND_STRING("git diff");
      }
      return false;
      break;
    case gitpush:
      if (record->event.pressed) {
        SEND_STRING("git push\n");
      }
      return false;
      break;
    case gitpull:
      if (record->event.pressed) {
        SEND_STRING("git pull\n");
      }
      return false;
      break;    
  }
  return true;
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Perfil: Common\n"), false);
            oled_write_P(PSTR(" ```    |  kc_lng1\n"), false);
            oled_write_P(PSTR("alt+4   |  alt+5 \n"), false);
            oled_write_P(PSTR("alt+6   |  alt+7   "), false);
            break;
        case 1:
            oled_write_P(PSTR("Perfil: Layers\n"), false);
            oled_write_P(PSTR("Media   |        \n"), false);
            oled_write_P(PSTR("Quantum |        \n"), false);
            oled_write_P(PSTR("GIT     |         "), false);
            break;
        case 2:
            oled_write_P(PSTR("Perfil: Quantum\n"), false);
            oled_write_P(PSTR("        |        \n"), false);
            oled_write_P(PSTR("qk_boot |        \n"), false);
            oled_write_P(PSTR("        |  qk_exec"), false);
            break;
        case 3:
            oled_write_P(PSTR("Perfil: Media\n"), false);
            oled_write_P(PSTR("        |  next\n"), false);
            oled_write_P(PSTR("mute    |  back\n"), false);
            oled_write_P(PSTR("p/s     |         "), false);
            break;
        case 4:
            oled_write_P(PSTR("Perfil: GIT\n"), false);
            oled_write_P(PSTR("status  |  diff\n"), false);
            oled_write_P(PSTR("push    |  pull\n"), false);
            oled_write_P(PSTR("        |         "), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    return false;
}
#endif

// LALT(LCTL(KC_DEL))

// LEFT_SHIFT + KC_F$number works!
// LEFT_CTRL + KC_$letter works!

// KC_MPLY (play/stop) = It works with spotify

// 0xA5 is a Special Key (https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md#special-keys)
// 0x3E = F5
// 0x3F = F6
// 0x8d = KEY_UNKNOWN
// 0x34 = Ctrl + C

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case PB_1:
//      if (record->event.pressed) {
//        SEND_STRING("`");
////        register_code(KC_F24);
//      } else {
//            // when keycode QMKBEST is released
//      }
//      return false;
//      break;
//  }
//  return true;
//};

// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
// https://jayliu50.github.io/qmk-cheatsheet/
// https://github.com/qmk/qmk_firmware/blob/master/docs/configurator_default_keymaps.md

// https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2
// http://www.curlap.com/support/developers/curl/docs/rte/latest/en/docs/en/api-ref/Keycode.html

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#modifier-keys