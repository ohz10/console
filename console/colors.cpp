#include <console/colors.hpp>
#include <sstream>

namespace console { namespace color {

    auto rgb(const uint8_t r, const uint8_t g, const uint8_t b) -> Escape
    {
        std::ostringstream ss;
        ss  << "\x1b[38;2;" 
            << static_cast<int>(r) << ";" 
            << static_cast<int>(g) << ";" 
            << static_cast<int>(b) << "m";

        return ss.str();
    }

    const Escape black = "\033[30m";
    const Escape red = "\033[31m";
    const Escape green = "\033[32m";
    const Escape orange = "\033[33m";
    const Escape blue = "\033[34m";
    const Escape purple = "\033[35m";
    const Escape cyan = "\033[36m";
    const Escape grey = "\033[37m";
    const Escape dark_grey = "\033[90m";
    const Escape light_red = "\033[91m";
    const Escape light_green = "\033[92m";
    const Escape yellow = "\033[92m";
    const Escape light_blue = "\033[94m";
    const Escape light_purple = "\033[95m";
    const Escape light_cyan = "\033[96m";
    const Escape white = "\033[97m";
    
    const Escape default_foreground = "\033[39m";
}}

namespace console { namespace color { namespace bold {

    const Escape black = "\033[1;30m";
    const Escape red = "\033[1;31m";
    const Escape green = "\033[1;32m";
    const Escape orange = "\033[1;33m";
    const Escape blue = "\033[1;34m";
    const Escape purple = "\033[1;35m";
    const Escape cyan = "\033[1;36m";
    const Escape grey = "\033[1;37m";

}}}

