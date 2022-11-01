#include <console/progress_bar.hpp>
#include <sstream>

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
    
    auto ProgressBar::before_update(const Escape& escapeSeq) -> ProgressBar&
    {
        before_ = escapeSeq;
        return *this;
    }
    
    auto ProgressBar::on_finish(const std::string& msg) -> ProgressBar&
    {
        finished_ = msg;
        return *this;
    }

    auto ProgressBar::bars() -> std::string
    {
        std::ostringstream ss;
        ss << bracket_color_ << left_ << color_;
        
        uint16_t bars = (width_ * percent()) / 100;
        
        for(uint16_t i = 0; i < bars; ++i)
        {
            ss << style_;
        }
    
        ss << std::string(width_ - bars, ' ') << bracket_color_ << right_;
        
        return ss.str();
    }

    auto ProgressBar::update(const uint64_t by_count) -> std::pair<std::string, Status>
    {
        count_ += by_count;
        
        const auto done = done_;
        done_ = count_ >= max_;
        count_ = done_ ? max_ : count_;
        
        const auto bar_msg = imbue(
                before_
              , bars()
              , message_);

        return done 
            ? std::make_pair(finished_, Status::Complete)
            : std::make_pair(bar_msg, Status::Continue);
    }
}}
