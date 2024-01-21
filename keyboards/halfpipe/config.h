// Copyright 2023 Philippe Daouadi (@Philippe Daouadi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN 0
#define SERIAL_USART_RX_PIN 1
#define MASTER_LEFT

// #define SERIAL_DEBUG

// The pin connected to the data pin of the LEDs
// #define WS2812_DI_PIN GP15
// The number of LEDs connected
// #define RGB_MATRIX_LED_COUNT 43

#define ENABLE_RGB_MATRIX_RAINBOW_BEACON 1
#define ENABLE_RGB_MATRIX_HUE_WAVE 1
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE 1
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE 1
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE 1
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_BEACON
#define RGB_MATRIX_DEFAULT_HUE 130
