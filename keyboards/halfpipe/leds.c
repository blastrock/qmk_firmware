#include <quantum/rgb_matrix/rgb_matrix_types.h>
#include <quantum.h>
#include <rgb_matrix.h>

// led_config_t g_led_config = {
//     {
//         // Key Matrix to LED Index
//         {0, 1, 2, 3, 4, 5, 6},
//         {7, 8, 9, 10, 11, 12, 13},
//         {14, 15, 16, 17, 18, 19, 20},
//         {21, 22, 23, 24, 25, 26, 27},
//         {28, 29, 30, 31, 32, 33},
//         {34, 35, 36, 37},
//         {38, 39, 40, 41, 42},
//     },
//     {
//         // LED Index to Physical Position
//         // clang-format off
//         {0, 0}, {10, 0}, {20, 0}, {30, 0}, {40, 0}, {50, 0}, {60, 0},
//         {0, 10}, {10, 10}, {20, 10}, {30, 10}, {40, 10}, {50, 10}, {60, 10},
//         {0, 20}, {10, 20}, {20, 20}, {30, 20}, {40, 20}, {50, 20}, {60, 20},
//         {0, 30}, {10, 30}, {20, 30}, {30, 30}, {40, 30}, {50, 30}, {60, 30},
//         {0, 40}, {10, 40}, {20, 40}, {30, 40}, {40, 40}, {50, 40},
//         {0, 50}, {10, 50}, {20, 50}, {30, 50},
//         {40, 60}, {50, 60}, {60, 60}, {50, 60}, {60, 60},
//     },
//     {
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//         1,
//     },
// };

// void keyboard_post_init_user(void) {
//     rgb_matrix_enable();
//     rgb_matrix_set_color_all(0, 255, 0);
//     rgb_matrix_mode(RGB_MATRIX_RAINBOW_BEACON);
//     rgb_matrix_set_speed(50);
//     //  Customise these values to desired behaviour
//     // debug_enable = true;
//     // debug_matrix = true;
//     //  debug_keyboard = true;
//     //  debug_mouse=true;
// }
