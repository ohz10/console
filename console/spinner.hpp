#pragma once

#include <console/console_color.hpp>
#include <console/escape.hpp>
#include <console/progress.hpp>

#include <chrono>
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
        auto on_finish(const std::string& msg) -> Spinner&;

    public:
        auto update(const uint64_t by_count) -> std::pair<std::string, Status>;

    private:
        std::string style_ = "|/-\\";
        std::string message_;
        std::string finished_;

        ConsoleColor color_;

        uint8_t position_ = 0;
    };
}}

