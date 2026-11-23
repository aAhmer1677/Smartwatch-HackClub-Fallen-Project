#pragma once

#include <cstdint>

namespace smartwatch {

struct State {
    int32_t accel_mg[3];
    int32_t gyro_mdps[3];
    uint32_t battery_mv;
    int32_t encoder_delta;
};

bool init();
void get_state(State &state);
void haptic(bool enabled);
void haptic_pulse(uint32_t ms);
bool touch_read(uint16_t &x, uint16_t &y);

} // namespace smartwatch
