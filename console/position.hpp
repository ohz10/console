#pragma once

#include <cstdint>
#include <limits>
#include <iostream>

namespace console { namespace cursor {

    struct Position
    {
        static const uint16_t Current = std::numeric_limits<uint16_t>::max();
        
        uint16_t row = Current;
        uint16_t column = Current;
        
        auto is_default() const -> bool { return row == Current && column == Current; }
    };
    
    std::ostream& operator<<(std::ostream& os, const Position& pos);
}}
