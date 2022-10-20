#include <console/position.hpp>
#include <console/cursor.hpp>

namespace console { namespace cursor {
    
    std::ostream& operator<<(std::ostream& os, const Position& pos)
    {
        os << cursor::go_to(pos);
        return os;
    }
}}
