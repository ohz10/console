#pragma once

#include <console/console_color.hpp>
#include <console/escape.hpp>
#include <console/progress_indicator.hpp>

#include <cstdint>
#include <string>
#include <utility>

namespace console { namespace progress {

    class ProgressBar : public ProgressIndicator
    {
    public:
        ProgressBar(const uint16_t width, const uint64_t max);

        auto style(const std::string& chars) -> ProgressBar&;
        auto color(const ConsoleColor& color) -> ProgressBar&;
        
        auto bracket_color(const ConsoleColor& color) -> ProgressBar&;
        auto left(const std::string& l) -> ProgressBar&;
        auto right(const std::string& r) -> ProgressBar&;
        
        auto message(const std::string& msg) -> ProgressBar&;
        auto on_finish(const std::string& msg) -> ProgressBar&;

    public:
        auto update(const uint64_t by_count) -> std::pair<std::string, Status>;

    private:
        auto bars() -> std::string;
        
    private:
        std::string style_ = "■";
        
        std::string left_ = "[";
        std::string right_ = "]";
        
        std::string message_;
        std::string finished_;

        ConsoleColor color_;
        ConsoleColor bracket_color_;
        
        uint16_t width_;
    };
}}
