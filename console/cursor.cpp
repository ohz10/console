#include <console/cursor.hpp>
#include <console/position.hpp>

#include <sstream>

namespace console { namespace cursor {

    using namespace std::literals::string_literals;

    const Escape hide = "\033[?25l";
    const Escape show = "\033[?25h";
    
    const Escape home = "\033[H";

    auto go_to(const Position& pos) -> std::string
    {
        if(pos.is_default())
        {
            return "";
        }
        
        std::ostringstream ss;
        ss << "\033[";
        
        if(pos.row != Position::Current)
        {
            ss << pos.row;
        }
        
        ss << ";";
        
        if(pos.column != Position::Current)
        {
            ss << pos.column;
        }
        ss << "H";
        
        return ss.str();
    }
    
    auto go_to(const uint16_t row, const uint16_t column) -> std::string 
    {
        return "\033["s + std::to_string(row) + ";" + std::to_string(column) + "H";
    }
    
    auto go_col(const uint16_t column) -> std::string
    {
        return "\033["s + std::to_string(column) + "G";
    }

    auto up(const uint16_t rows) -> std::string
    {
        return "\033["s + std::to_string(rows) + "A";
    }

    auto down(const uint16_t rows) -> std::string
    {
        return "\033["s + std::to_string(rows) + "B";
    }

    auto right(const uint16_t columns) -> std::string
    {
        return "\033["s + std::to_string(columns) + "C";
    }

    auto left(const uint16_t columns) -> std::string
    {
        return "\033["s + std::to_string(columns) + "D";
    }
}}

