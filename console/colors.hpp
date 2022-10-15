#pragma once
#include <console/escape.hpp>
#include <cstdint>

namespace console { namespace color {

    auto rgb(const uint8_t r, const uint8_t g, const uint8_t b) -> Escape;

    extern const Escape black;
    extern const Escape red;
    extern const Escape green;
    extern const Escape orange;
    extern const Escape blue;
    extern const Escape purple;
    extern const Escape cyan;
    extern const Escape grey;
    extern const Escape dark_grey;
    extern const Escape light_red;
    extern const Escape light_green;
    extern const Escape yellow;
    extern const Escape light_blue;
    extern const Escape light_purple;
    extern const Escape light_cyan;
    extern const Escape white;

}}

namespace console { namespace color { namespace bold {

    extern const Escape black;
    extern const Escape red;
    extern const Escape green;
    extern const Escape orange;
    extern const Escape blue;
    extern const Escape purple;
    extern const Escape cyan;
    extern const Escape grey;
    
}}}

