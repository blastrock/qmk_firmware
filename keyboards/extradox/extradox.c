#include "extradox.h"

bool pca9555_status = false;

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable   = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}

bool init_pca9555(void) {
    pca9555_status = 1;

    // I2C subsystem

    // uint8_t sreg_prev;
    // sreg_prev=SREG;
    // cli();

    pca9555_init(I2C_ADDR);
    // i2c_init(); // on pins D(1,0)
    // _delay_ms(1000);

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    pca9555_status = pca9555_set_config(I2C_ADDR, 0, 0b00000000);
    if (!pca9555_status) goto out;
    pca9555_status = pca9555_set_config(I2C_ADDR, 1, 0b11111111);

#ifdef LEFT_LEDS
    if (!pca9555_status) pca9555_status = ergodox_left_leds_update();
#endif // LEFT_LEDS

    // SREG=sreg_prev;

out:
    return pca9555_status;
}

void extradox_blink_all_leds(void) {
    extradox_right_led_1(true);
    _delay_ms(50);
    extradox_right_led_2(true);
    _delay_ms(50);
    extradox_right_led_3(true);
    _delay_ms(50);
    extradox_right_led_1(false);
    _delay_ms(50);
    extradox_right_led_2(false);
    _delay_ms(50);
    extradox_right_led_3(false);
}
