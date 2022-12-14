#include <console/spinner.hpp>

namespace console { namespace progress {

    Spinner::Spinner(const uint64_t max)
        : ProgressIndicator(max)
    {
    }

    auto Spinner::style(const std::string& chars) -> Spinner&
    {
        style_ = chars;
        return *this;
    }       

    auto Spinner::color(const ConsoleColor& color) -> Spinner&
    {
        color_ = color;
        return *this;
    }

    auto Spinner::message(const std::string& msg) -> Spinner&
    {
        message_ = msg;
        return *this;
    }

    auto Spinner::before_update(const Escape& escapeSeq) -> Spinner&
    {
        before_ = escapeSeq;
        return *this;
    }
    
    auto Spinner::on_finish(const std::string& msg) -> Spinner&
    {
        finished_ = imbue(msg, cursor::show);
        return *this;
    }

    auto Spinner::update(const uint64_t by_count) -> std::pair<std::string, Status>
    {
        count_ += by_count;
        
        const auto done = count_ >= max_;
        count_ = done ? max_ : count_;

        const auto pos = position_++ % style_.length();
        const auto spinner_msg = imbue(
              before_
            , color_
            , style_.at(pos)
            , message_);

        return done 
            ? std::make_pair(finished_, Status::Complete)
            : std::make_pair(spinner_msg, Status::Continue);
    }
}}

