#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"



enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  SWITCH_MY,
  SWITCH_QWERTY,
  
};

enum layers {
  MY,
  QWERTY,
  FLAYER,
  MLAYER,
};

#define MY_Q KC_Q
#define MY_W KC_G
#define MY_E KC_M
#define MY_R KC_L
#define MY_T KC_W
#define MY_Y KC_Y
#define MY_U KC_U
#define MY_I KC_F
#define MY_O KC_B
#define MY_P KC_SCOLON

#define MY_A KC_D
#define MY_S KC_S
#define MY_D KC_T
#define MY_F KC_N
#define MY_G KC_R
#define MY_H KC_I
#define MY_J KC_A
#define MY_K KC_E
#define MY_L KC_O
#define MY_SCOLON KC_H

#define MY_Z KC_DOT
#define MY_X KC_Z
#define MY_C KC_C
#define MY_V KC_P
#define MY_B KC_V
#define MY_N KC_J
#define MY_M KC_X
#define MY_COMMA KC_K
#define MY_DOT KC_COMMA
#define MY_SLASH KC_SLASH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [MY] = KEYMAP(
      KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_DELETE,
      KC_EQUAL,MY_Q,MY_W,MY_E,MY_R,MY_T,OSL(FLAYER),
      KC_ESCAPE,MY_A,MY_S,MY_D,MY_F,MY_G,
      KC_LSHIFT,LCTL_T(MY_Z),MY_X,MY_C,MY_V,MY_B,KC_LBRACKET,
      KC_PSCREEN,KC_LALT,KC_LGUI,KC_LEFT,KC_RIGHT,
      
      KC_HOME,KC_END,
      KC_TRANSPARENT,
      KC_SPACE,KC_BSPACE,KC_APPLICATION,
      
      KC_INSERT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
      OSL(MLAYER),MY_Y,MY_U,MY_I,MY_O,MY_P,KC_BSLASH,
      MY_H,MY_J,MY_K,MY_L,MY_SCOLON,KC_QUOTE,
      KC_RBRACKET,MY_N,MY_M,MY_COMMA,MY_DOT,RCTL_T(MY_SLASH),KC_RSHIFT,
      KC_UP,KC_DOWN,KC_RGUI,KC_RALT,LSFT(KC_INSERT),
      
      KC_PGUP,KC_PGDOWN,
      KC_TRANSPARENT,
      KC_CAPS,KC_TAB,KC_ENTER
      ),

  [QWERTY] = KEYMAP(
      KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_DELETE,
      KC_EQUAL,KC_Q,KC_W,KC_E,KC_R,KC_T,OSL(FLAYER),
      KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,
      KC_LSHIFT,LCTL_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_LBRACKET,
      KC_TRANSPARENT,KC_LALT,KC_LGUI,KC_LEFT,KC_RIGHT,
      
      KC_HOME,KC_END,
      KC_TRANSPARENT,
      KC_SPACE,KC_BSPACE,KC_APPLICATION,
      
      KC_INSERT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
      OSL(MLAYER),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
      KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,
      KC_RBRACKET,KC_N,KC_M,KC_COMMA,KC_DOT,RCTL_T(KC_SLASH),KC_RSHIFT,
      KC_UP,KC_DOWN,KC_RGUI,KC_RALT,LSFT(KC_INSERT),
      
      KC_PGUP,KC_PGDOWN,
      KC_TRANSPARENT,
      KC_CAPS,KC_TAB,KC_ENTER
      ),

  [FLAYER] = KEYMAP(
      KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,TG(FLAYER),
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

      RGB_MOD,KC_TRANSPARENT,
      KC_TRANSPARENT,
      RGB_VAD,RGB_VAI,KC_TRANSPARENT,
      
      KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      
      RGB_TOG,RGB_SLD,
      KC_TRANSPARENT,
      KC_TRANSPARENT,RGB_HUD,RGB_HUI
      ),

  //[FLAYER] = KEYMAP(
  //    KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
  //    KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,TG(FLAYER),
  //    KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
  //    KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
  //    KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

  //    RGB_MOD,KC_TRANSPARENT,
  //    KC_TRANSPARENT,
  //    RGB_VAD,RGB_VAI,KC_TRANSPARENT,
  //    
  //    KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
  //    KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_ASTERISK,KC_F12,
  //    KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,KC_TRANSPARENT,
  //    KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_TRANSPARENT,
  //    KC_TRANSPARENT,KC_DOT,KC_0,KC_EQUAL,KC_TRANSPARENT,
  //    
  //    RGB_TOG,RGB_SLD,
  //    KC_TRANSPARENT,
  //    KC_TRANSPARENT,RGB_HUD,RGB_HUI
  //    ),

  [MLAYER] = KEYMAP(
      SWITCH_MY,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      SWITCH_QWERTY,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_MS_WH_UP,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_DOWN,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,
      
      KC_TRANSPARENT,RESET,
      KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

      KC_TRANSPARENT,KC_TRANSPARENT,KC_NUMLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
      TG(MLAYER),KC_TRANSPARENT,KC_KP_7,KC_KP_8,KC_KP_9,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_KP_4,KC_KP_5,KC_KP_6,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,KC_KP_0,KC_KP_DOT,KC_TRANSPARENT,KC_TRANSPARENT,
      
      KC_TRANSPARENT,KC_TRANSPARENT,
      KC_TRANSPARENT,
      KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
      ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

void send_mod_string(bool shift, unsigned key1, unsigned key2) {
  const uint8_t mods = get_mods();
  if (mods & MOD_BIT(KC_LSHIFT))
    unregister_code(KC_LSHIFT);
  if (mods & MOD_BIT(KC_RSHIFT))
    unregister_code(KC_RSHIFT);
  SEND_STRING(SS_TAP(X_APPLICATION));
  if (shift)
    register_code(KC_LSHIFT);
  register_code(key1);
  unregister_code(key1);
  if (shift)
    unregister_code(KC_LSHIFT);
  if (mods & MOD_BIT(KC_LSHIFT))
    register_code(KC_LSHIFT);
  if (mods & MOD_BIT(KC_RSHIFT))
    register_code(KC_RSHIFT);
  register_code(key2);
  unregister_code(key2);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (IS_LAYER_ON(FLAYER) && record->event.pressed) {
    bool processed = false;
    switch(keycode) {
    case KC_E:
      send_mod_string(false, KC_QUOTE, KC_E);
      processed = true;
      break;
    case KC_F:
      send_mod_string(true, KC_CIRCUMFLEX, KC_E);
      processed = true;
      break;
    case KC_B:
      send_mod_string(false, KC_GRAVE, KC_E);
      processed = true;
      break;
    case KC_U:
      send_mod_string(false, KC_GRAVE, KC_U);
      processed = true;
      break;
    case KC_Y:
      send_mod_string(true, KC_CIRCUMFLEX, KC_U);
      processed = true;
      break;
    case KC_A:
      send_mod_string(false, KC_GRAVE, KC_A);
      processed = true;
      break;
    case KC_O:
      send_mod_string(true, KC_CIRCUMFLEX, KC_O);
      processed = true;
      break;
    case KC_C:
      send_mod_string(false, KC_COMMA, KC_C);
      processed = true;
      break;
    case KC_COMMA:
      send_mod_string(false, KC_O, KC_E);
      processed = true;
      break;
    case KC_X:
      send_mod_string(true, KC_CIRCUMFLEX, KC_A);
      processed = true;
      break;
    case KC_I:
      send_mod_string(true, KC_CIRCUMFLEX, KC_I);
      processed = true;
      break;
    }
    if (processed) {
      if (is_oneshot_layer_active()) {
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      }
      return false;
    }
  }
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
#ifdef RGBLIGHT_ENABLED
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
#endif
    case SWITCH_MY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(MY);
      }
      return true;
    case SWITCH_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(QWERTY);
      }
      return true;
    
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer-1) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
