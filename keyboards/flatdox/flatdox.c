#include "flatdox.h"

bool         i2c_initialized = 0;
i2c_status_t mcp23018_status = 0x20;

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable   = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}

uint8_t init_mcp23018(void) {
    mcp23018_status = 0x20;

    // I2C subsystem

    // uint8_t sreg_prev;
    // sreg_prev=SREG;
    // cli();

    if (i2c_initialized == 0) {
        i2c_init(); // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }
    // i2c_init(); // on pins D(1,0)
    // _delay_ms(1000);

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111110, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b00000000, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0b11111110, FLATDOX_I2C_TIMEOUT);
    if (mcp23018_status) goto out;

out:
    i2c_stop();

#ifdef LEFT_LEDS
    if (!mcp23018_status) mcp23018_status = ergodox_left_leds_update();
#endif // LEFT_LEDS

    // SREG=sreg_prev;

    return mcp23018_status;
}

void flatdox_blink_all_leds(void) {
    flatdox_right_led_1(true);
    _delay_ms(50);
    flatdox_right_led_2(true);
    _delay_ms(50);
    flatdox_right_led_3(true);
    _delay_ms(50);
    flatdox_right_led_1(false);
    _delay_ms(50);
    flatdox_right_led_2(false);
    _delay_ms(50);
    flatdox_right_led_3(false);
}
