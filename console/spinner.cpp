#include <console/spinner.hpp>

#include <console/cursor.hpp>
#include <console/imbue.hpp>
#include <console/line.hpp>

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

    auto Spinner::on_finish(const std::string& msg) -> Spinner&
    {
        finished_ = imbue(msg, cursor::show);
        return *this;
    }

    auto Spinner::update(const uint64_t by_count) -> std::pair<std::string, Status>
    {
        count_ += by_count;
        
        if(count_ >= max_)
        {
            const auto finish_msg = imbue(line::clear,cursor::go_col(1), finished_);
            return std::make_pair(finish_msg, Status::Complete);
        }

        const auto c = position_++ % style_.length();
        const auto spinner_msg = imbue(
              line::clear
            , cursor::go_col(1)
            , color_
            ,style_.at(c)
            , message_);

        return std::make_pair(spinner_msg, Status::Continue);
    }
}}

