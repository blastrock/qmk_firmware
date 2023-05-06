#pragma once

#include "quantum.h"
#include "action_layer.h"
#include "pca9555.h"
#include <stdint.h>
#include <stdbool.h>
// #include <hal.h>

// I2C aliases and register addresses
#define I2C_ADDR 0b0100000
#define I2C_ADDR_WRITE ((I2C_ADDR << 1) | I2C_WRITE)
#define I2C_ADDR_READ ((I2C_ADDR << 1) | I2C_READ)
#define IODIRA 0x00 // i/o direction register
#define IODIRB 0x01
#define GPPUA 0x0C // GPIO pull-up resistor register
#define GPPUB 0x0D
#define GPIOA 0x12 // general purpose i/o port register (write modifies OLAT)
#define GPIOB 0x13
#define OLATA 0x14 // output latch register
#define OLATB 0x15

extern bool pca9555_status;
#define ERGOPLUS_I2C_TIMEOUT 100

bool init_pca9555(void);

static inline void extradox_right_led_1(bool on) {
    writePin(D2, on);
}
static inline void extradox_right_led_2(bool on) {
    writePin(D3, on);
}
static inline void extradox_right_led_3(bool on) {
    writePin(E6, on);
}

void extradox_blink_all_leds(void);

// clang-format off
/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT_extradox_pretty(                                            \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,           R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46, \
    L50, L51, L52, L53, L54,                     R52, R53, R54, R55, R56, \
                             L65, L66, R60, R61,                          \
                                  L64, R62,                               \
                        L63, L62, L61, R65, R64, R63                    ) \
                                                                          \
  /* matrix positions */                                                  \
  {                                                                       \
    {L00, L10, L20, L30, L40, L50, KC_NO},                                     \
        {L01, L11, L21, L31, L41, L51, L61},                                   \
        {L02, L12, L22, L32, L42, L52, L62},                                   \
        {L03, L13, L23, L33, L43, L53, L63},                                   \
        {L04, L14, L24, L34, L44, L54, L64},                                   \
        {L05, L15, L25, L35, L45, KC_NO, L65},                                 \
        {L06, L16, L26, KC_NO, L46, KC_NO, L66},                               \
                                                                          \
        {R00, R10, R20, KC_NO, R40, KC_NO, R60},                               \
        {R01, R11, R21, R31, R41, KC_NO, R61},                                 \
        {R02, R12, R22, R32, R42, R52, R62},                                   \
        {R03, R13, R23, R33, R43, R53, R63},                                   \
        {R04, R14, R24, R34, R44, R54, R64},                                   \
        {R05, R15, R25, R35, R45, R55, R65},                                   \
    {                                                                     \
      R06, R16, R26, R36, R46, R56       , KC_NO                               \
    }                                                                     \
  }
// clang-format on
