
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>
#include <stdlib.h>
#define OLED_FONT_HEIGHT 2

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
  gitpull,
  gitadd,
  gitcommit,
  gitlog,
  gitdiffstaged
};

enum teste {
  b1 = SAFE_RANGE,
  b2,
  b3,
  b4,
  b5,
  b6,
  b7,
  b8,
  b9
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*    Common Layer
              ┌─────────┐
              │ Layers  │
              └─────────┘
    ┌─────────┬─────────┬─────────┐
    │   `     │ LNG1    │ Alt+1   │
    ├─────────┼─────────┼─────────┤
    │ Alt+2   │ Alt+3   │ Alt+4   │
    ├─────────┼─────────┼─────────┤
    │ Alt+5   │ Alt+6   │ Alt+7   │
    └─────────┴─────────┴─────────┘ 


      Layers - Used to switch between layers
              ┌─────────┐
              │  base   │
              └─────────┘
    ┌─────────┬─────────┬─────────┐
    │ Media   │ teste   │         │
    ├─────────┼─────────┼─────────┤
    │ Quantum │         │         │
    ├─────────┼─────────┼─────────┤
    │ Git     │         │         │
    └─────────┴─────────┴─────────┘ 

      Quantum_layer - Used to update the firmware
              ┌─────────┐
              │  Layers │
              └─────────┘
    ┌─────────┬─────────┬─────────┐
    │         │         │         │
    ├─────────┼─────────┼─────────┤
    │ QK_BOOT │         │         │
    ├─────────┼─────────┼─────────┤
    │         │         │         │
    └─────────┴─────────┴─────────┘ 


      Media_layer - Used to control Media
              ┌─────────┐
              │ Layers  │
              └─────────┘
    ┌─────────┬─────────┬─────────┐
    │ Prev    │ Mute    │ Next    │
    ├─────────┼─────────┼─────────┤
    │ Pla/Sto │         │         │
    ├─────────┼─────────┼─────────┤
    │         │         │         │
    └─────────┴─────────┴─────────┘ 


      GIT
              ┌─────────┐
              │ Layers  │
              └─────────┘
    ┌─────────┬─────────┬─────────┐
    │ DIFF    │ PULL    │ PUSH    │
    ├─────────┼─────────┼─────────┤
    │ STATUS  │ ADD     │ COMMIT  │
    ├─────────┼─────────┼─────────┤
    │ LOG     │LOGSTAGED│         │
    └─────────┴─────────┴─────────┘ 
  */


  // Base or Common layer
	[0] = LAYOUT(
    TO(1),
		BR_ACUT,     LT(2, KC_LNG1), LALT(KC_P1),
    LALT(KC_P2), LALT(KC_P3),    LALT(KC_P4),
		LALT(KC_P5), LALT(KC_P6),    LALT(KC_P7)
	),
  // Layers (2=quantum | 3=media | 4=git | 0=base)
	[1] = LAYOUT(
        TO(0),
        TO(3), TO(5), KC_NO,
        TO(2), TO(0), KC_NO,
        TO(4), KC_NO, KC_NO
    ),
  // Quantum
	[2] = LAYOUT(
        TO(1),
        KC_NO,     KC_NO, KC_NO,
        QK_BOOT,   KC_NO, KC_NO,
        KC_NO,     KC_NO, KC_NO
    ),
  // Media
	[3] = LAYOUT(
        TO(1),
        KC_NO,   KC_MNXT, KC_NO,
        KC_MUTE, KC_MPRV, KC_NO,
        KC_MPLY, KC_NO,   KC_NO
    ),
  // GIT
	[4] = LAYOUT(
        TO(1),
        gitdiff, gitpull, gitpush,
        gitstatus, gitadd, gitcommit,
        gitlog, gitdiffstaged, KC_EXEC
    ),
	[5] = LAYOUT(
        TO(1),
        b1, b2, b3,
        b4, b5, b6,
        b7, b8, b9
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
        SEND_STRING("git diff\n");
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
    case gitadd:
      if (record->event.pressed) {
        SEND_STRING("git add\n");
      }
      return false;
      break;   
    case gitcommit:
      if (record->event.pressed) {
        SEND_STRING("git commit\n");
      }
      return false;
      break;   
    case gitlog:
      if (record->event.pressed) {
        SEND_STRING("git log --oneline --decorate --parents\n");
      }
      return false;
      break;   
    case gitdiffstaged:
      if (record->event.pressed) {
        SEND_STRING("git diff --staged\n");
      }
      return false;
      break;  
// teste
//    case b1:
//      if (record->event.pressed) {
//        SEND_STRING("b1\n");
//      }
//      return false;
//      break;  
//    case b2:
//      if (record->event.pressed) {
//        SEND_STRING("b2\n");
//      }
//      return false;
//      break;  
//    case b3:
//      if (record->event.pressed) {
//        SEND_STRING("b3\n");
//      }
//      return false;
//      break;  
//    case b4:
//      if (record->event.pressed) {
//        SEND_STRING("b4\n");
//      }
//      return false;
//      break;  
//    case b5:
//      if (record->event.pressed) {
//        SEND_STRING("b5\n");
//      }
//      return false;
//      break;  
//    case b6:
//      if (record->event.pressed) {
//        SEND_STRING("b6\n");
//      }
//      return false;
//      break;  
//    case b7:
//      if (record->event.pressed) {
//        SEND_STRING("b7\n");
//      }
//      return false;
//      break;  
//    case b8:
//      if (record->event.pressed) {
//        SEND_STRING("b8\n");
//      }
//      return false;
//      break;  
//    case b9:
//      if (record->event.pressed) {
//        SEND_STRING("b9\n");
//      }
//      return false;
//      break;
  }
  return true;
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Perfil: Common\n"), false);
            oled_write_P(PSTR(" `   |LNG1 |Alt+1\n"), false);
            oled_write_P(PSTR("alt+2|alt+3|Alt+4\n"), false);
            oled_write_P(PSTR("alt+5|alt+6|Alt+7"), false);
            break;
        case 1:
            oled_write_P(PSTR("Perfil: Layers            \n"), false);
            oled_write_P(PSTR("Media   | Teste           \n"), false);
            oled_write_P(PSTR("Quantum | Base            \n"), false);
            oled_write_P(PSTR("GIT     |                   "), false);
            break;
        case 2:
            oled_write_P(PSTR("Perfil: Quantum           \n"), false);
            oled_write_P(PSTR("        |                 \n"), false);
            oled_write_P(PSTR("qk_boot |                 \n"), false);
            oled_write_P(PSTR("        |  qk_exec          "), false);
            break;
        case 3:
            oled_write_P(PSTR("Perfil: Media             \n"), false);
            oled_write_P(PSTR("back   |  mute   |  next  \n"), false);
            oled_write_P(PSTR("p/s    |  mprv            \n"), false);
            oled_write_P(PSTR("       |                    "), false);
            break;
        case 4:
            oled_write_P(PSTR("Perfil: GIT                 \n"), false);
            oled_write_P(PSTR("diff   |  pull | push       \n"), false);
            oled_write_P(PSTR("status |  add  | commit     \n"), false);
            oled_write_P(PSTR("log    | diff2 |              "), false);
            break;
        case 5:
            oled_write_P(PSTR("Perfil: TESTE               \n"), false);
            oled_write_P(PSTR("b1 | b2 | b3                \n"), false);
            oled_write_P(PSTR("b4 | b5 | b6                \n"), false);
            oled_write_P(PSTR("b7 | b8 | b9                \n"), false);
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