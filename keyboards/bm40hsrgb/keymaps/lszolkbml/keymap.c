// qmk flash -kb bm40hsrgb -km signynt

/* Copyright 2021 Vincenzo Mitchell Barroso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// non-KC_ keycodes
#define KC_RST RESET
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

//define layers
enum layers {BASE, NAVR, NUMBER, COLORS, CODE, SECCODE, GAME, SECGAME};

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
};

//cmd tab

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LCTL);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 500) {
      unregister_code(KC_LCTL);
      is_cmd_tab_active = false;
    }
  }
}

//layer led colors

void rgb_matrix_indicators_user(void) {

//base indicators

if(IS_LAYER_ON(BASE)) {
//  rgb_matrix_set_color(0, 255, 255, 255);
//  rgb_matrix_set_color(0, 255, 0, 0);
//  rgb_matrix_set_color(40, 255, 50, 0);
//  rgb_matrix_set_color(37, 0, 0, 255);
//  rgb_matrix_set_color(45, 0, 255, 0);
//  rgb_matrix_set_color(46, 10, 0, 50);
//  rgb_matrix_set_color(42, 255, 0, 0);
//  rgb_matrix_set_color(43, 50, 0, 0);
}

//game indicators

if(IS_LAYER_ON(GAME)) {
  rgb_matrix_set_color_all(50, 50, 50);

  rgb_matrix_set_color(11, 255, 0, 0);


  rgb_matrix_set_color(2, 255, 0, 0);

  rgb_matrix_set_color(13, 255, 0, 0);
  rgb_matrix_set_color(14, 255, 0, 0);
  rgb_matrix_set_color(15, 255, 0, 0);

  rgb_matrix_set_color(35, 0, 255, 0);


  rgb_matrix_set_color(39, 255, 0, 0);

}

if(IS_LAYER_ON(SECGAME)) {
  rgb_matrix_set_color_all(50, 50, 50);

  rgb_matrix_set_color(11, 0, 0, 0);

  rgb_matrix_set_color(0, 0, 0, 0);
  rgb_matrix_set_color(1, 255, 0, 0);
  rgb_matrix_set_color(2, 255, 0, 0);
  rgb_matrix_set_color(3, 255, 0, 0);
  rgb_matrix_set_color(4, 255, 0, 0);
  rgb_matrix_set_color(5, 255, 0, 0);
  rgb_matrix_set_color(6, 255, 0, 0);
  rgb_matrix_set_color(7, 255, 0, 0);
  rgb_matrix_set_color(8, 255, 0, 0);
  rgb_matrix_set_color(9, 255, 0, 0);
  rgb_matrix_set_color(10, 255, 0, 0);

  rgb_matrix_set_color(12, 255, 100, 0);
  rgb_matrix_set_color(13, 255, 100, 0);
  rgb_matrix_set_color(14, 255, 100, 0);
  rgb_matrix_set_color(15, 255, 100, 0);
  rgb_matrix_set_color(16, 255, 100, 0);
  rgb_matrix_set_color(17, 255, 100, 0);
  rgb_matrix_set_color(18, 255, 100, 0);
  rgb_matrix_set_color(19, 255, 100, 0);
  rgb_matrix_set_color(20, 255, 100, 0);
  rgb_matrix_set_color(21, 255, 100, 0);
  rgb_matrix_set_color(22, 255, 100, 0);
  rgb_matrix_set_color(23, 255, 100, 0);


  rgb_matrix_set_color(39, 255, 0, 0);

}

//layer indicators

if(IS_LAYER_ON(NAVR)) {
  rgb_matrix_set_color(37, 0, 0, 255);

  rgb_matrix_set_color(0, 255, 100, 0);
  rgb_matrix_set_color(12, 0, 255, 0);
  rgb_matrix_set_color(24, 0, 0, 255);
  rgb_matrix_set_color(36, 255, 0, 0);

  rgb_matrix_set_color(5, 0, 255, 0);
  rgb_matrix_set_color(4, 0, 255, 0);
  rgb_matrix_set_color(3, 0, 255, 0);
  rgb_matrix_set_color(2, 0, 255, 0);
  rgb_matrix_set_color(1, 255, 255, 255);
  rgb_matrix_set_color(11, 255, 0, 0);

  rgb_matrix_set_color(17, 255, 0, 0);
  rgb_matrix_set_color(16, 255, 0, 0);
  rgb_matrix_set_color(15, 255, 0, 0);
  rgb_matrix_set_color(14, 255, 255, 255);
  rgb_matrix_set_color(13, 10, 0, 0);

  rgb_matrix_set_color(7, 50, 50, 50);
  rgb_matrix_set_color(8, 255, 100, 0);
  rgb_matrix_set_color(9, 50, 50, 50);

  rgb_matrix_set_color(19, 255, 100, 0);
  rgb_matrix_set_color(20, 255, 100, 0);
  rgb_matrix_set_color(21, 255, 100, 0);

  rgb_matrix_set_color(43, 255, 0, 0);
  rgb_matrix_set_color(44, 255, 0, 0);
  rgb_matrix_set_color(45, 255, 0, 0);
  rgb_matrix_set_color(46, 255, 0, 0);

}

if(IS_LAYER_ON(NUMBER)) {
  rgb_matrix_set_color(42, 255, 0, 0);

  rgb_matrix_set_color(1, 255, 0, 0);
  rgb_matrix_set_color(2, 255, 0, 0);
  rgb_matrix_set_color(3, 255, 0, 0);
  rgb_matrix_set_color(4, 255, 0, 0);
  rgb_matrix_set_color(5, 255, 0, 0);
  rgb_matrix_set_color(6, 255, 0, 0);
  rgb_matrix_set_color(7, 255, 0, 0);
  rgb_matrix_set_color(8, 255, 0, 0);
  rgb_matrix_set_color(9, 255, 0, 0);
  rgb_matrix_set_color(10, 255, 0, 0);

  rgb_matrix_set_color(19, 255, 100, 0);
  rgb_matrix_set_color(20, 255, 100, 0);
  rgb_matrix_set_color(21, 255, 100, 0);
  rgb_matrix_set_color(22, 255, 100, 0);
  rgb_matrix_set_color(23, 255, 100, 0);

  rgb_matrix_set_color(13, 0, 255, 0);
  rgb_matrix_set_color(14, 0, 255, 0);
  rgb_matrix_set_color(15, 0, 255, 0);
  rgb_matrix_set_color(16, 0, 255, 0);
  rgb_matrix_set_color(17, 0, 255, 0);
  rgb_matrix_set_color(18, 0, 255, 0);
  rgb_matrix_set_color(25, 0, 255, 0);
  rgb_matrix_set_color(26, 0, 255, 0);
  rgb_matrix_set_color(27, 0, 255, 0);
  rgb_matrix_set_color(28, 0, 255, 0);
  rgb_matrix_set_color(29, 0, 255, 0);
  rgb_matrix_set_color(30, 0, 255, 0);

  rgb_matrix_set_color(31, 0, 0, 255);

  rgb_matrix_set_color(43, 255, 100, 0);
  rgb_matrix_set_color(44, 255, 100, 0);
  rgb_matrix_set_color(45, 255, 100, 0);
  rgb_matrix_set_color(46, 255, 100, 0);
}

if(IS_LAYER_ON(COLORS)) {

  rgb_matrix_set_color(1, 255, 0, 0);
  rgb_matrix_set_color(2, 0, 255, 0);
  rgb_matrix_set_color(3, 0, 0, 255);
  rgb_matrix_set_color(4, 255, 0, 255);
  rgb_matrix_set_color(5, 255, 255, 0);
  rgb_matrix_set_color(6, 0, 255, 255);
  rgb_matrix_set_color(7, 255, 255, 255);
  rgb_matrix_set_color(8, 255, 100, 255);
  rgb_matrix_set_color(9, 255, 100, 0);

  rgb_matrix_set_color(11, 0, 255, 0);
}

//capslock leds

if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color_all(50, 15.6, 0);
  }

}

//tap dance declarations
enum {
    TD_MEDIA, TD_SCREEN,
};

//tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA] = ACTION_TAP_DANCE_DOUBLE( KC_MPLY , KC_MNXT ),
    [TD_SCREEN] = ACTION_TAP_DANCE_DOUBLE( (G(S(KC_S))) , S(C(KC_4)) ),
};

#define KC_TD(TD_VARIABLE) TD(TD_VARIABLE)

//--------------------------------------------------------------------------------------------------------

//base

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,      KC_W,       KC_E,     KC_R,      KC_T,           KC_Y,    KC_U,      KC_I,     KC_O,    KC_P,     KC_BSPC,
    KC_TAB,   KC_A,      KC_S,       KC_D,     KC_F,      KC_G,           KC_H,    KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,      KC_X,       KC_C,     KC_V,      KC_B,           KC_N,    KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL,  MO(NAVR),  KC_LALT,    KC_LGUI,  KC_LSFT,         KC_SPC,           MO(NUMBER),   KC_LEFT,  KC_UP,   KC_DOWN,  KC_RGHT
  ),

//layers
  [NAVR] = LAYOUT_planck_mit(
    RGB_TOG,    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,  RGB_SPI, KC_NO,  KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_RST,
    KC_NO,      RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, RGB_SPD, KC_NO,  KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,
    TG(COLORS), KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,
    TG(GAME),   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_BSPC,     KC_NO,   KC_MPRV, KC_VOLU, KC_VOLD, KC_TD(TD_MEDIA)
  ),
  [NUMBER] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,   KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_F1,  KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LSFT, KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_COMM,  KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_NO,  KC_LALT, KC_UNDS,  KC_LSFT,      KC_SPC,      KC_NO,    KC_HOME, KC_PGUP, KC_PGDN, KC_END
  ),
  [GAME] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,        KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    TG(GAME),
    KC_TAB,  KC_A,    KC_S,    KC_D,        KC_F,    KC_G,    KC_H,    KC_J,     KC_K,     KC_L,    KC_QUOT, KC_LSFT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,        KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LALT, KC_NO,   MO(SECGAME), KC_LALT,     KC_SPC,       KC_BSPC,  KC_DEL,   KC_MPRV, KC_MPLY, KC_MNXT
  ),
  [SECGAME] = LAYOUT_planck_mit(
    KC_MINS, KC_1,    KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_EQL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_NO,   KC_NO,   KC_NO,   KC_P1,    KC_P2,    KC_P3,   KC_P4,   KC_P5,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_NO,      KC_NO,         KC_P6,    KC_P7,    KC_P8,   KC_P9,   KC_P0
  ),
  [COLORS] = LAYOUT_planck_mit(
    KC_MINS, KC_1,    KC_2,    KC_3,        KC_4,    KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    TG(COLORS),
    KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,  KC_F12,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_NO,   KC_NO,   KC_NO,   KC_P1,    KC_P2,    KC_P3,   KC_P4,   KC_P5,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     KC_NO,      KC_NO,         KC_P6,    KC_P7,    KC_P8,   KC_P9,   KC_P0
  )
};
