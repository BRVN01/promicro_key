
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>

// I can create a custom keycode:
//enum my_keycodes {
//  FOO = SAFE_RANGE,
//  BAR = SAFE_RANGE
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*    Common Layer
    ┌───────┬───────┐
    │   `   │  LNG1 │
    ├───────┼───────┤ ┌───────┐
    │ Alt+4 │ Alt+5 │ │Layers │
    ├───────┼───────┤ └───────┘
    │ Alt+6 │ Alt+7 │
    └───────┴───────┘
  
      Quantum_layer
    ┌───────┬───────┐
    │       │       │
    ├───────┼───────┤ ┌───────┐
    │QK_BOOT│       │ │Layers │
    ├───────┼───────┤ └───────┘
    │       │       │
    └───────┴───────┘  

      Media_layer
    ┌───────┬───────┐
    │       │ Next  │
    ├───────┼───────┤ ┌───────┐
    │ Mute  │ Prev  │ │Layers │ // Mute Output song | 
    ├───────┼───────┤ └───────┘
    │ Pl/St │       │ // Play and Stop | 
    └───────┴───────┘  

      Layers
    ┌─────────┬─────────┐
    │ Common  │         │
    ├─────────┼─────────┤ ┌─────────┐
    │ Quantum │ Media   │ │ Layers  │
    ├─────────┼─────────┤ └─────────┘
    │         │         │
    └─────────┴─────────┘  


  */

	[0] = LAYOUT(
		BR_ACUT, LT(1, KC_LNG1), 
    LALT(KC_P4), LALT(KC_P5), TO(1),
		LALT(KC_P6), LALT(KC_P7)
	),
	[1] = LAYOUT(
        TO(3), KC_NO, 
        TO(2), KC_NO, TO(0),
        KC_NO, KC_NO
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
    )


//	[0] = LAYOUT(
//		KC_P2, KC_P1, 
//    KC_P4, KC_P5, TO(1),
//		KC_P6, KC_P7
//	),
//	[1] = LAYOUT(
//		KC_NO, KC_NO, 
//    TO(2), KC_NO, TO(0),
//		KC_NO, KC_NO
//	),
//	[2] = LAYOUT(
//        KC_B, KC_W, 
//        KC_C, KC_D, TO(1),
//        KC_G, KC_L
//    )
};

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