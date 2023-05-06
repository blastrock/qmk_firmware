/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2015 ZSA Technology Labs Inc (@zsa)
Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "extradox.h"

/* matrix state(1:on, 0:off) */
extern matrix_row_t matrix[MATRIX_ROWS];     // debounced values
extern matrix_row_t raw_matrix[MATRIX_ROWS]; // raw values

static matrix_row_t read_cols(uint8_t row);
static void         init_cols(void);
static void         unselect_rows(void);
static void         select_row(uint8_t row);

static uint8_t pca9555_reset_loop;

void matrix_init_custom(void) {
    // initialize row and col

    pca9555_status = init_pca9555();

    setPinOutput(D3);
    setPinOutput(D2);
    setPinOutput(B0);

    unselect_rows();
    init_cols();

    extradox_blink_all_leds();
}

// Reads and stores a row, returning
// whether a change occurred.
static inline bool store_raw_matrix_row(matrix_row_t current_matrix[], uint8_t index) {
    matrix_row_t temp = 0x7F & read_cols(index);
    if (current_matrix[index] != temp) {
        // uprintf("value changed (%d) %d -> %d\n", (int)index, (int)current_matrix[index], (int)temp);
        current_matrix[index] = temp;
        return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    if (!pca9555_status) { // if there was an error
        if (++pca9555_reset_loop == 0) {
            pca9555_status = init_pca9555();
            if (!pca9555_status) {
                print("left side not responding\n");
            } else {
                print("left side attached\n");
                extradox_blink_all_leds();
            }
        }
    }

    bool changed = false;

    for (uint8_t i = 0; i < MATRIX_ROWS_PER_SIDE; i++) {
        // select rows from left and right hands
        uint8_t left_index  = i;
        uint8_t right_index = i + MATRIX_ROWS_PER_SIDE;
        select_row(left_index);
        select_row(right_index);

        changed |= store_raw_matrix_row(current_matrix, left_index);
        changed |= store_raw_matrix_row(current_matrix, right_index);

        unselect_rows();
    }

    return changed;
}

/* Column pin configuration
 *
 * ATmega32U4
 * col: 0   1   2   3   4   5   6
 * pin: C6  B6  B5  B4  D7  D6  D4
 *
 * PCA9555
 * col: 0   1   2   3   4   5
 * pin: 10  11  12  13  14  15 (port/bit)
 */
static void init_cols(void) {
    // init on pca9555
    // not needed, already done as part of init_pca9555()

    // init on atmel
    setPinInputHigh(C6);
    setPinInputHigh(B6);
    setPinInputHigh(B5);
    setPinInputHigh(B4);
    setPinInputHigh(D7);
    setPinInputHigh(D6);
    setPinInputHigh(D4);
}

static matrix_row_t read_cols(uint8_t row) {
    if (row < MATRIX_ROWS_PER_SIDE) {
        if (!pca9555_status) { // if there was an error
            uprintf("no read, i2c error\n");
            return 0;
        } else {
            static unsigned char reverse_bits[16] = {
                0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe, 0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf,
            };

            uint8_t data   = 0;
            pca9555_status = pca9555_readPins(I2C_ADDR, 1, &data);

            data = (reverse_bits[data & 0xf] << 4) | reverse_bits[data >> 4];
            data >>= 1;
            return ~data;
        }
        return 0;
    } else {
        /* read from atmel
         */

        // uint8_t vals = (PINC & (1 << 6)) | ((PINB & (0b111 << 4)) >> 1) | ((PIND & (0b11 << 6)) >> 5) | ((PIND & (1 << 4)) >> 3);
        uint8_t vals = (PINC & (1 << 6)) | ((PINB & (1 << 6)) >> 1) | ((PINB & (1 << 5)) >> 1) | ((PINB & (1 << 4)) >> 1) | ((PIND & (1 << 7)) >> 5) | ((PIND & (1 << 6)) >> 5) | ((PIND & (1 << 4)) >> 4);
        return ~vals;
    }
}

/* Row pin configuration
 *
 * ATmega32U4
 * row: 7   8   9   10  11  12  13
 * pin: F0  F1  F4  F5  F6  F7  D5
 *
 * PCA9555
 * row: 0   1   2   3   4   5   6
 * pin: 10  11  12  13  14  15  16 (port/bit)
 */
static void unselect_rows(void) {
    // no need to unselect on pca9555, because the select step sets all
    // the other row bits high, and it's not changing to a different
    // direction

    // unselect on atmel
    setPinInput(F0);
    setPinInput(F1);
    setPinInput(F4);
    setPinInput(F5);
    setPinInput(F6);
    setPinInput(F7);
    setPinInput(D5);
}

static void select_row(uint8_t row) {
    if (row < 7) {
        // select on pca9555
        if (pca9555_status) {
            // set active row low  : 0
            // set other rows hi-Z : 1
            // row == 5 is actually GPIOB(0)
            pca9555_status = pca9555_set_output(I2C_ADDR, 0, 0xFF & ~(1 << row));
        }
    } else {
        // select on teensy
        // Output low(DDR:1, PORT:0) to select
        switch (row) {
            case 7:
                setPinOutput(F0);
                writePinLow(F0);
                break;
            case 8:
                setPinOutput(F1);
                writePinLow(F1);
                break;
            case 9:
                setPinOutput(F4);
                writePinLow(F4);
                break;
            case 10:
                setPinOutput(F5);
                writePinLow(F5);
                break;
            case 11:
                setPinOutput(F6);
                writePinLow(F6);
                break;
            case 12:
                setPinOutput(F7);
                writePinLow(F7);
                break;
            case 13:
                setPinOutput(D5);
                writePinLow(D5);
                break;
        }
    }
}

// DO NOT REMOVE
// Needed for proper wake/sleep
void matrix_power_up(void) {
    pca9555_status = init_pca9555();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}
