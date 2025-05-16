#include <quantum.h>
#include "mechapress.h"

void mechapress_blink_all_leds(void) {
    mechapress_right_led_1(true);
    _delay_ms(50);
    mechapress_right_led_2(true);
    _delay_ms(50);
    mechapress_right_led_1(false);
    _delay_ms(50);
    mechapress_right_led_2(false);
    _delay_ms(50);
    mechapress_right_led_1(true);
    _delay_ms(50);
    mechapress_right_led_2(true);
    _delay_ms(50);
    mechapress_right_led_1(false);
    _delay_ms(50);
    mechapress_right_led_2(false);
    _delay_ms(50);
}

void keyboard_post_init_user(void) {
    //  Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    //  debug_keyboard = true;
    //  debug_mouse=true;

    setPinOutput(B0);
    setPinOutput(D5);

    mechapress_blink_all_leds();
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    mechapress_right_led_1(false);
    mechapress_right_led_2(false);
    switch (layer - 1) {
        case 0:
            break;
        case 1:
            mechapress_right_led_1(true);
            break;
        case 2:
            mechapress_right_led_2(true);
            break;
    }

    return layer_state_set_user(state);
};
