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

#define SOFT_SERIAL_PIN D1
#define EE_HANDS

#define SERIAL_DEBUG

#define WS2812_T1H 600
#define WS2812_T0H 300
#define WS2812_TIMING 900
#define WS2812_TRST 90
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200

#define AUDIO_PIN B6
#define AUDIO_CLICKY

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_MACOS
