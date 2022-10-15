#include <console/screen.hpp>

namespace console { namespace screen {
    
    const Escape clear = "\033[2J";
    const Escape clear_above = "\033[1J";
    const Escape clear_below = "\033[0J";

}}
