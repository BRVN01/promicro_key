
#include QMK_KEYBOARD_H
#include <sendstring_brazilian_abnt2.h>
#include <stdlib.h>

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
  gitdiffstaged,
  mutt_s,
  vagrant_up,
  vagrant_init,
  vagrant_destroy,
  vagrant_halt,
  vagrant_vali,
  vagrant_status,
  vagrant_ssh
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
    │ Prev    │ M-AU    │ Next    │
    ├─────────┼─────────┼─────────┤
    │ Pla/Sto │ Conf    │ M-MI    │
    ├─────────┼─────────┼─────────┤
    │ V-Do    │ V-UP    │         │
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
    KC_NO,       TO(1),          KC_NO,
		LALT(KC_P8), LT(2, KC_LNG1), LALT(KC_P1),
    LALT(KC_P2), LALT(KC_P3),    LALT(KC_P4),
		LALT(KC_P5), LALT(KC_P6),    LALT(KC_P7)
	),
  // Layers (2=quantum | 3=media | 4=git | 0=base)
	[1] = LAYOUT(
        KC_NO, TO(0), KC_NO,
        TO(3), TO(5), KC_NO,
        TO(2), TO(6), KC_NO,
        TO(4), TO(7), KC_NO
    ),
  // Quantum
	[2] = LAYOUT(
        KC_NO,     TO(1), KC_NO,
        KC_NO,     KC_NO, KC_NO,
        QK_BOOT,   KC_NO, KC_NO,
        KC_NO,     KC_NO, KC_NO
    ),
  // Media
	[3] = LAYOUT(
        KC_NO,   TO(1),   KC_NO,
        KC_MPRV, KC_MUTE, KC_MNXT,
        KC_MPLY, KC_MSEL, LCTL(LSFT(KC_A)),
        KC_VOLD, KC_VOLU, BR_ACUT
    ),
  // GIT
	[4] = LAYOUT(
        KC_NO,     TO(1),         KC_NO,
        gitdiff,   gitpull,       gitpush,
        gitstatus, gitadd,        gitcommit,
        gitlog,    gitdiffstaged, BR_ACUT
    ),
  // DISCORD
	[5] = LAYOUT(
        KC_NO,              TO(1),             KC_NO,
        LCTL(LSFT(KC_F1)),  LCTL(LSFT(KC_F2)), KC_NO,
        KC_NO,              KC_NO,             KC_NO,
        KC_NO,              KC_NO,             KC_NO
    ),
  // Mutt
	[6] = LAYOUT(
        KC_NO,    TO(1),    KC_NO,
        KC_Q,     KC_UP,    KC_I,
        KC_LEFT,  KC_ENT,   KC_RIGHT,
        mutt_s,   KC_DOWN,  KC_END
    ),
  // Vagrant
	[7] = LAYOUT(
        KC_NO,            TO(1),         KC_NO,
        vagrant_status,   vagrant_up,    vagrant_init,
        vagrant_destroy,  vagrant_vali,  KC_NO,
        vagrant_halt,     vagrant_ssh,   KC_NO
    )
//	[5] = LAYOUT(
//        KC_NO,   TO(1),
//        b1, b2, b3,
//        b4, b5, b6,
//        b7, b8, b9
//    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {    
    case BR_ACUT:
      if (record->event.pressed) {
        SEND_STRING("`");
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
        SEND_STRING("git add");
      }
      return false;
      break;   
    case gitcommit:
      if (record->event.pressed) {
        SEND_STRING("git commit -m");
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

    case vagrant_up:
      if (record->event.pressed) {
        SEND_STRING("vagrant up\n");
      }
      return false;
      break;
    case vagrant_init:
      if (record->event.pressed) {
        SEND_STRING("vagrant init ");
      }
      return false;
      break;
    case vagrant_destroy:
      if (record->event.pressed) {
        SEND_STRING("vagrant destroy -f\n");
      }
      return false;
      break;
    case vagrant_halt:
      if (record->event.pressed) {
        SEND_STRING("vagrant halt\n");
      }
      return false;
      break;
    case vagrant_vali:
      if (record->event.pressed) {
        SEND_STRING("vagrant validate \n");
      }
      return false;
      break;
    case vagrant_status:
      if (record->event.pressed) {
        SEND_STRING("vagrant status\n");
      }
      return false;
      break;
    case vagrant_ssh:
      if (record->event.pressed) {
        SEND_STRING("vagrant ssh ");
      }
      return false;
      break;
    case mutt_s:
      if (record->event.pressed) {
        register_code(KC_O);
        unregister_code(KC_O);
        register_code(KC_R);      
        unregister_code(KC_R);
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
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|ALT8 | LNG1 | ALT1|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|ALT2 | ALT3 | ALT4|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|ALT5 | ALT6 | ALT7|\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 1:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|SONG | DISC |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|UPDA | MUTT |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|GIT  | VAGR |     |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 2:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|BOOT |      |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 3:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|BACK | M/AU | NEXT|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|P/S  | CONF | M/MI|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|V/DO | V/UP | `   |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 4:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|DIFF | PULL | PUSH|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|STAT | ADD  | COMM|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|LOG  | DIF2 | `   |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 5:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|NF-M | NF-S |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 6:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("| Q   | UP   | I   |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("| LEFT| ENTER| RIGH|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("| O+R | DOWN | END |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
        case 7:
            oled_write_P(PSTR(" __________________ \n"), false);
            oled_write_P(PSTR("|     |      |     |\n"), false);
            oled_write_P(PSTR("|STAT | UP   | INIT|\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|DEST | VALI |     |\n"), false);
            oled_write_P(PSTR("|-----|------|-----|\n"), false);
            oled_write_P(PSTR("|HALT | SSH  |     |\n"), false);
            oled_write_P(PSTR("|_____|______|_____|\n"), false);
            break;
//        case 5:
//            oled_write_P(PSTR("Perfil: TESTE\n"), false);
//            oled_write_P(PSTR("b1 | b2 | b3 \n"), false);
//            oled_write_P(PSTR("b4 | b5 | b6 \n"), false);
//            oled_write_P(PSTR("b7 | b8 | b9 \n"), false);
//            break;
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
