#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    KC_F23,          KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,  KC_MPLY,
    KC_F13,   KC_F14,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, KC_HOME,
    KC_F15,   KC_F16,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F17,   KC_F18,   KC_F24, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_F19,   KC_F20,   KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_F21,   KC_F22,  KC_LCTL, KC_LGUI, KC_LALT, MO(1),    KC_BSPC,   KC_BSPC,           KC_SPC,  KC_SPC, MO(1) , KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_HUI, RGB_HUD, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PSCR,
    RGB_SAI, RGB_SAD, RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_VAI, RGB_VAD, KC_CAPS, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_MPRV, KC_MNXT, _______, _______, _______, _______, KC_DEL, KC_DEL,          _______, _______, _______, _______, _______, KC_WBAK, _______, KC_WFWD
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch(biton32(layer_state)) {
        case 1:
          if(clockwise)
      {
       tap_code16(C(KC_MINS));
      } else {
       tap_code16(C(KC_EQL));
      }
      break;
        default:
          if (clockwise) {
              tap_code(KC_MS_WH_UP);
          } else {
              tap_code(KC_MS_WH_DOWN);
          }
          break;
      }
    } else if (index == 1) {
      switch(biton32(layer_state)) {
           case 1:
          if(clockwise)
      {
        tap_code(KC_UP);
      } else {
        tap_code(KC_DOWN);
      }
      break;
        default:
          if (clockwise) {
              tap_code(KC_VOLD);
          } else {
              tap_code(KC_VOLU);
          }
          break;
      }
    }
}
