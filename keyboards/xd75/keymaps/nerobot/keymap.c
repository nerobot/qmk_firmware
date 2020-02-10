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
 
 #include "keymap_steno.h"
 
#include QMK_KEYBOARD_H

// Layer shorthand
#define _QW 0
#define _RAISE 1
#define _LOWER 2
#define _PLVR 3 // Plover layer

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

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC, 		KC_1,    	KC_2,    	KC_3,    	KC_4,    		KC_5,    	KC_7,			KC_8, 		KC_9,		KC_6,    	KC_7,    	KC_8,    	KC_9,    	KC_0,    	KC_DEL,
    ALT_T(KC_TAB),	KC_QUOT, 	KC_COMM, 	KC_DOT,  	KC_P,    		KC_Y,    	KC_4,			KC_5,  		KC_6, 		KC_F,    	KC_G,   	KC_C,    	KC_R,    	KC_L,    	ALT_T(KC_MINS),
    KC_LSFT,		KC_A,    	KC_O,    	KC_E,    	KC_U,    		KC_I,    	KC_1,			KC_2,  		KC_3, 		KC_D,    	KC_H,    	KC_T,    	KC_N,    	KC_S,    	KC_RSFT,
    CTL_T(KC_ESC),	KC_SCLN, 	KC_Q,    	KC_J,    	KC_K,    		KC_X,    	KC_0,			KC_0,  		KC_DOT,		KC_B,    	KC_M,   	KC_W,    	KC_V,    	KC_Z,    	CTL_T(KC_ENT),
    _______, 		_______ , 	KC_LWIN, 	KC_LGUI, 	KC_LGUI, 		MO(_RAISE),	KC_BSPACE,		KC_0,		KC_SPC,		MO(_LOWER),	KC_RALT,	KC_RALT, 	KC_RALT, 	KC_RGUI, 	KC_RCTL
  ),


  [_LOWER] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   		KC_F5,   	_______, 	_______, 	_______, 	KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
    _______,		KC_1,    	KC_2,    	KC_3,    	KC_4,			KC_5,    	_______,	_______,	_______,	KC_6, 		KC_7,  		KC_8,    	KC_9,    	KC_0,    	_______,
    KC_CAPS, 		KC_NUBS, 	KC_LCBR, 	KC_RCBR, 	KC_EQL,  		KC_SLSH, 	_______,   	_______,   	_______,   	_______, 	KC_HOME, 	KC_PGDOWN, 	KC_PGUP, 	KC_END, 	_______,
    _______,   		KC_NUHS,   	KC_NUHS,   	KC_TILD,   	KC_UNDS,   		KC_MINS,   	_______, 	_______, 	_______, 	_______,   	_______,   	_______,   	_______,   	_______,  	_______,
    _______, 		_______, 	_______, 	_______, 	_______,		KC_DEL, 	_______, 	_______,   	_______, 	_______, 	_______, 	_______, 	_______, 	_______, 	_______
  ),


  [_RAISE] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   		KC_F5,   	_______, 	_______, 	_______, 	KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
    KC_ESC,			LSFT(KC_1),	LSFT(KC_2), LSFT(KC_3),	LSFT(KC_4),		LSFT(KC_5),	_______,	_______,	_______,	LSFT(KC_6),	LSFT(KC_7),	LSFT(KC_8),	LSFT(KC_9),	LSFT(KC_0),	KC_DEL,
    KC_MPRV, 		KC_PIPE, 	KC_LBRC, 	KC_RBRC, 	KC_PPLS,  		KC_QUES, 	_______,   	_______,   	_______,   	KC_PLUS, 	KC_LEFT, 	KC_DOWN, 	KC_UP  , 	KC_RGHT, 	_______,
    KC_F1,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   		KC_F5,   	_______, 	_______, 	_______, 	KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
    _______, 		_______, 	_______, 	_______, 	_______,		KC_DEL, 	_______, 	_______,   	_______, 	KC_PENT, 	KC_PENT, 	_______, 	_______, 	_______, 	_______
  ),

  [_PLVR] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   		KC_F5,   	_______, 	_______, 	_______, 	KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
    KC_ESC,			LSFT(KC_1),	LSFT(KC_2), LSFT(KC_3),	LSFT(KC_4),		LSFT(KC_5),	_______,	_______,	_______,	LSFT(KC_6),	LSFT(KC_7),	LSFT(KC_8),	LSFT(KC_9),	LSFT(KC_0),	KC_DEL,
    KC_MPRV, 		STN_S1, 	STN_TL, 	STN_PL, 	STN_HL, 		STN_ST1, 	_______,   	_______,   	_______,   	STN_ST3, 	STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
    KC_F1,   		STN_S2, 	STN_KL, 	STN_WL, 	STN_RL, 		STN_ST2,   	_______, 	_______, 	_______, 	STN_ST4, 	STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
    TG(_PLVR), 		_______, 	_______, 	_______, 	STN_A,  		STN_O, 		_______, 	_______,   	_______, 	STN_E,   	STN_U, 	_______, 	_______, 	_______, 	_______
  ),

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

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  // ...
  steno_set_mode(STENO_MODE_GEMINI);
};
