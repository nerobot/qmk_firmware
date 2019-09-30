/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QW 0
#define _FN 1
#define _L1 2  		// Currently not used

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

enum {
  TD_SFT_CAP = 0
};


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SFT_CAP]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CLCK)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC             | 1      | 2      | 3      | 4      | 5      | <      | =+     | >      | 6      		| 7      		| 8      | 9      | 0      |                |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB             | '      | ,      | .      | p      | y      | [ {    |        | ] }    | f      		| g      		| c      | r      | l      | -_             |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TD(TD_SFT_CAP)  | a      | o      | e      | u      | i      | (      |        | )      | d      		| h      		| t      | n      | s      | TD(TD_SFT_CAP) |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LCTRL / ESC     | ;      | q      | j      | k      | x      | {      |        | }      | b      		| m      		| w      | v      | z      | ENTER          |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL           | Fn     | Win    | LAlt   | BACKSP | DEL    | \      |        | /      | Fn / SPACE	| Fn / SPACE	|        |        |        | RCTRL          |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC, 		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LABK, KC_EQL,  KC_RABK, KC_6,    		KC_7,    		KC_8,    KC_9,    KC_0,    _______,
    KC_TAB,  		KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_LBRC, KC_BSLS, KC_RBRC, KC_F,    		KC_G,    		KC_C,    KC_R,    KC_L,    KC_MINS,
    TD(TD_SFT_CAP),	KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_LPRN, KC_DEL,  KC_RPRN, KC_D,    		KC_H,    		KC_T,    KC_N,    KC_S,    TD(TD_SFT_CAP),
    CTL_T(KC_ESC),	KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LCBR, KC_UP,   KC_RCBR, KC_B,    		KC_M,    		KC_W,    KC_V,    KC_Z,    KC_ENT,
    KC_LCTL, 		MO(_FN), KC_LWIN, KC_LALT, KC_BSPC, KC_DEL , KC_BSLS, KC_DOWN, KC_SLSH, LT(_FN,KC_SPC),	LT(_FN,KC_SPC),	MO(_FN), KC_RALT, KC_RGUI, KC_RCTL
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F1     | F2     | F3     | F4     | F5     | NUM LK | P/     | P*     | F6     | F7     | F8     | F9     | F10    | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      | LEFT   | DOWN   | UP     | RIGHT  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD |        |  P0    | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET,
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, _______, RGB_TOG, RGB_RMOD,RGB_MOD, _______, KC_P0,   KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
  ),

      /* MOVEMENT LAYER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      | LEFT   | DOWN   | UP     | RIGHT  |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| LUp    |        | P0     | P.     | LDown  | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_L1] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, _______, RGB_TOG, RGB_RMOD,TG(_L1), _______, KC_P0,   KC_PDOT, TG(_L1), KC_PENT, MO(_FN), _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}