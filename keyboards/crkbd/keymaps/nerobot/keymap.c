#include QMK_KEYBOARD_H

/*#include "keymap_steno.h"*/

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _PLOVER 4


enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  PLOVER,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

/*uint16_t get_tapping_term(uint16_t keycode)*/
/*{*/
    /*switch (keycode)*/
    /*{*/
        /*case ALT_T(KC_SPC):*/
            /*return 3000;*/
            /*break;*/
        /*case CTL_T(KC_BSPC):*/
            /*return 3000;*/
            /*break;*/
        /*default:*/
            /*return 3000;*/
            /*break;*/
    /*}*/
/*}*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( \
  //,-----------------------------------------------------------------------.                	,-----------------------------------------------------------------------.
     ALT_T(KC_TAB),		KC_QUOT,	KC_COMM,	KC_DOT,		KC_P,		KC_Y,                   		KC_F,		KC_G,		KC_C,		KC_R,		KC_L,		ALT_T(KC_BSPC),\
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_LSFT,		KC_A,		KC_O,		KC_E,		KC_U,		KC_I,                   		KC_D,		KC_H,		KC_T,		KC_N,		KC_S,		KC_RSFT,\
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+-----------+-----------+-----------+-----------|
     CTL_T(KC_ESC),	KC_SCLN,	KC_Q,		KC_J,		KC_K,		KC_X,                   		KC_B,		KC_M,		KC_W,		KC_V,		KC_Z,		CTL_T(KC_ENT),\
  //|-----------+-------------+----------+----------+-----------+-----------+------|  |---------+-----------+-----------+-----------+-----------+-----------+------------|
												SFT_T(KC_ESC),	RAISE, 	CTL_T(KC_BSPC),		ALT_T(KC_SPC),		LOWER,		SFT_T(KC_ENT) \
                                             //`-----------------------------------'  `--------------------'
  ),
  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------------------------.                	,-----------------------------------------------------------------------.
     _______,		KC_1,    	KC_2,    	KC_3,    	KC_4,		KC_5,    						KC_6, 		KC_7,  		KC_8,    	KC_9,    	KC_0,  		LCTL(LALT(KC_DEL))		,
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_CAPS, 		KC_NUBS, 	KC_LCBR, 	KC_RCBR, 	KC_EQL,  	KC_SLSH,   						_______, 	KC_HOME, 	KC_PGDOWN, 	KC_PGUP, 	KC_END, 	_______,
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+-----------+-----------+-----------+-----------|
    KC_CAPS, 		KC_NUBS, 	KC_NUHS, 	LSFT(KC_NUHS), 	KC_UNDS,  	KC_MINS,   					_______, 	KC_HOME, 	KC_PGDOWN, 	KC_PGUP, 	KC_END, 	_______,
  //|-----------+-------------+----------+----------+-----------+-----------+------|  |---------+-----------+-----------+-----------+-----------+-----------+------------|
												KC_LGUI,	RAISE	,		KC_DEL,			KC_ENT,			LOWER,		KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------------------------.                	,-----------------------------------------------------------------------.
     KC_ESC,		LSFT(KC_1),	LSFT(KC_2),	LSFT(KC_3),	LSFT(KC_4),	LSFT(KC_5),						LSFT(KC_6),	LSFT(KC_7),	LSFT(KC_8),	LSFT(KC_9),	LSFT(KC_0),	LALT(KC_F4), \
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+€-----------+-----------+-----------+-----------|
     KC_MPRV, 		LSFT(KC_NUBS), 	KC_LBRC, 	KC_RBRC, 	KC_PPLS,  	KC_QUES,						KC_PLUS, 	KC_LEFT, 	KC_DOWN, 	KC_UP  , 	KC_RGHT, 	_______,
  //|-----------+-------------+----------+----------+-----------+-----------|                	|-----------+-----------+-----------+-----------+-----------+-----------|
     KC_F1,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   	KC_F5, 							KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
  //|-----------+-------------+----------+----------+-----------+-----------+------|  |---------+-----------+-----------+-----------+-----------+-----------+------------|
												KC_LGUI,	RAISE,		KC_DEL,			KC_ENT,			LOWER,		KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
	 RESET,   		KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,   	KC_F5, 							KC_F6,   	KC_F7,   	KC_F8,   	KC_F9,   	KC_F10,  	RESET,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    LCTL(LALT(KC_DEL)),	RGB_HUI,	RGB_SAI,	RGB_VAI,	KC_NO,		KC_NO,                 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		TO( _PLOVER),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     _______,		RGB_HUD,	RGB_SAD,	RGB_VAD,	KC_NO,		KC_NO,                 		KC_NO, 		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, RAISE,KC_SPC,   KC_ENT, LOWER,KC_RALT \
                              //`--------------------'  `--------------------'
  ),
/*    [_PLOVER] = LAYOUT( \*/
  /*//,-----------------------------------------------------.                    ,-----------------------------------------------------.*/
       /*KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,\*/
  /*//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
       /*KC_TAB,    STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,\*/
  /*//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
    /*TG( _PLOVER), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                  STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,\*/
  /*//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|*/
											/*STN_A,  STN_O,  KC_SPC,     KC_ENT,  STN_E,   STN_U \*/
	/*)*/
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
	  /*steno_set_mode(STENO_MODE_GEMINI);*/

    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
	/*steno_set_mode(STENO_MODE_GEMINI);*/
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
/*    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
	  */
  }
  return true;
}
