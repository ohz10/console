#include <console/progress_bar.hpp>

#include <console/cursor.hpp>
#include <console/imbue.hpp>
#include <console/line.hpp>

namespace console { namespace progress {

    ProgressBar::ProgressBar(const uint16_t width, const uint64_t max) 
        : ProgressIndicator(max)
        , width_(width)
    {
    }

    auto ProgressBar::style(const std::string& chars) -> ProgressBar&
    {
        style_ = chars;
        return *this;
    }
    
    auto ProgressBar::color(const ConsoleColor& color) -> ProgressBar&
    {
        color_ = color;
        return *this;
    }
    
    auto ProgressBar::bracket_color(const ConsoleColor& color) -> ProgressBar&
    {
        bracket_color_ = color;
        return *this;
    }
    
    auto ProgressBar::left(const std::string& l) -> ProgressBar&
    {
        left_ = l;
        return *this;
    }
    
    auto ProgressBar::right(const std::string& r) -> ProgressBar&
    {
        right_ = r;
        return *this;
    }
    
    auto ProgressBar::message(const std::string& msg) -> ProgressBar&
    {
        message_ = msg;
        return *this;
    }
    
    auto ProgressBar::on_finish(const std::string& msg) -> ProgressBar&
    {
        finished_ = msg;
        return *this;
    }

    auto ProgressBar::bars() -> std::string
    {
        std::string s;
        uint16_t bars = (width_ * percent()) / 100;
        
        for(uint16_t i = 0; i < bars; ++i)
        {
            s += style_;
        }
        
        return s;
    }

    auto ProgressBar::update(const uint64_t by_count) -> std::pair<std::string, Status>
    {
        count_ += by_count;
        
        const auto done = count_ >= max_;
        const auto tail = done ? finished_ : "";
        const auto msg = imbue(
              line::clear
            , cursor::go_col(1)
            , bracket_color_
            , left_
            , color_
            , bars()
            , cursor::go_col(width_ + 2)
            , bracket_color_
            , right_
            , message_
            , tail);

        return std::make_pair(msg, done ? Status::Complete : Status::Continue);
    }
}}
