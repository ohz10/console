#pragma once

#include <console/console_color.hpp>
#include <console/cursor.hpp>
#include <console/escape.hpp>
#include <console/imbue.hpp>
#include <console/line.hpp>
#include <console/progress_indicator.hpp>

#include <cstdint>
#include <string>
#include <utility>

namespace console { namespace progress {

    class Spinner : public ProgressIndicator
    {
    public:
        Spinner(const uint64_t max);

        auto style(const std::string& chars) -> Spinner&;
        auto color(const ConsoleColor& color) -> Spinner&;
        auto message(const std::string& msg) -> Spinner&;
        
        auto before_update(const Escape& escapeSeq) -> Spinner&;
        auto on_finish(const std::string& msg) -> Spinner&;

    public:
        auto update(const uint64_t by_count) -> std::pair<std::string, Status>;

    private:
        std::string style_ = "|/-\\";
        
        std::string before_ = imbue(cursor::go_col(1), line::clear_after);
        std::string message_;
        std::string finished_;

        ConsoleColor color_;

        uint8_t position_ = 0;
    };
}}

