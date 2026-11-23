#pragma once

#include <cstddef>
#include <cstdint>

namespace ble_uart {

void init();
bool connected();
void tx(const char *text);
void txf(const char *format, ...);

} // namespace ble_uart
