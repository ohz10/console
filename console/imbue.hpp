#pragma once
#include <console/escape.hpp>
#include <console/reset.hpp>

#include <sstream>

namespace console {

    template<typename... Args>
    auto imbue(Args&&... args) -> Escape
    {
        std::ostringstream ss;
        (ss << ... << args);

        ss << reset::all;
        return ss.str();
    }
}

