#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_APP, KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, MO(1), KC_BSPC, KC_SPC, MO(2), KC_ENT),
        [1] = LAYOUT(KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_NO, KC_NO, KC_EQL, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WREF, KC_WBAK, KC_UP, KC_WFWD, KC_LBRC, KC_RBRC, KC_LCTL, LCTL(KC_A), KC_NO, KC_NO, KC_LGUI, KC_APP, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_RCTL, KC_LSFT, KC_NO, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_RSFT, KC_NO, KC_TRNS, KC_NO, KC_SPC, MO(3), KC_ENT),
        [2] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, RGB_VAI, RGB_VAD, KC_MPRV, KC_MNXT, KC_NO, KC_NLCK, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_PAST, KC_LCTL, RGB_HUI, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PSLS, KC_NO, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PEQL, KC_LALT, MO(3), KC_DEL, KC_NO, KC_TRNS, KC_P0),
        [3] = LAYOUT(KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, LGUI(KC_TAB), LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T), LGUI(KC_Y), LGUI(KC_U), LGUI(KC_I), LGUI(KC_O), LGUI(KC_P), LGUI(KC_BSLS), KC_LCTL, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G), LGUI(KC_H), LGUI(KC_J), LGUI(KC_K), LGUI(KC_L), LGUI(KC_SCLN), LGUI(KC_QUOT), KC_NO, LGUI(KC_A), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B), KC_NO, KC_NO, LGUI(KC_N), LGUI(KC_M), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch(biton32(layer_state)) {
        case 1:
          if(clockwise)
      {
        tap_code(KC_RGHT);
      } else {
        tap_code(KC_LEFT);
      }
      break;
        default:
          if (clockwise) {
              tap_code(KC_MS_WH_DOWN);
          } else {
              tap_code(KC_MS_WH_UP);
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

