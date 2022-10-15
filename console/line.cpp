#include <console/line.hpp>

namespace console { namespace line {

    const Escape clear = "\033[2K";
    const Escape clear_before = "\033[1K";
    const Escape clear_after = "\033[0K";

}}
