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
    debug_matrix  = true;
    //  debug_keyboard = true;
    //  debug_mouse=true;

    mechapress_blink_all_leds();
}
