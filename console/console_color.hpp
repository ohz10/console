#pragma once

#include <console/background.hpp>
#include <console/colors.hpp>
#include <console/escape.hpp>

#include <iostream>

namespace console {

    struct ConsoleColor
    {
        Escape foreground = color::default_foreground;
        Escape background = background::default_background;
    };

    inline
    std::ostream& operator<<(std::ostream& os, const ConsoleColor& color)
    {
        os << color.foreground << color.background;
        return os;
    }
}
