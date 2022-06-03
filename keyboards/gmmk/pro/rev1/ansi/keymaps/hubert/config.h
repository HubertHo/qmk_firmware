#pragma once

#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

#undef DEBOUNCE
#define DEBOUNCE 8
