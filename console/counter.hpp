#pragma once

#include <console/background.hpp>
#include <console/console_color.hpp>
#include <console/cursor.hpp>
#include <console/escape.hpp>
#include <console/imbue.hpp>
#include <console/line.hpp>
#include <console/progress_indicator.hpp>

#include <cstdint>
#include <string>

namespace console { namespace progress {

    class Counter : public ProgressIndicator
    {
    public:
        Counter(const uint64_t max);

        auto left(const std::string& l) -> Counter&;
        auto right(const std::string& r) -> Counter&;
        
        auto bracket_color(const ConsoleColor& color) -> Counter&;
        auto count_color(const ConsoleColor& color) -> Counter&;
        auto total_color(const ConsoleColor& color) -> Counter&;
        auto message_color(const ConsoleColor& color) -> Counter&;

        auto message(const std::string& msg) -> Counter&;
        
        auto before_update(const Escape& escapeSeq) -> Counter&;
        auto on_finish(const std::string& msg) -> Counter&;

    public:
        auto update(const uint64_t by_count) -> std::pair<std::string, Status>;

    private:
        std::string message_;
        std::string before_ = imbue(cursor::go_col(1), line::clear_after);
        std::string finished_;

        std::string left_ = "[";
        std::string right_ = "]";
        
        ConsoleColor message_color_;
        ConsoleColor bracket_color_;
        ConsoleColor count_color_;
        ConsoleColor total_color_;
    };
}}
