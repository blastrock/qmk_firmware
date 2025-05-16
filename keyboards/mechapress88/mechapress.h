#include <quantum.h>

static inline void mechapress_right_led_1(bool on) {
    writePin(B0, !on);
}
static inline void mechapress_right_led_2(bool on) {
    writePin(D5, !on);
}
