#include <console/spinner.hpp>

#include <console/cursor.hpp>
#include <console/imbue.hpp>
#include <console/line.hpp>

namespace console { namespace spinners {

    Spinner::Spinner(const uint64_t max)
        : max_(max)
    {
    }

    auto Spinner::style(const std::string& chars) -> Spinner&
    {
        style_ = chars;
        return *this;
    }       

    auto Spinner::color(const Escape& color) -> Spinner&
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

    auto Spinner::update(const uint64_t by_count) -> std::pair<std::string, bool>
    {
        update_count_ += by_count;

        if(update_count_ >= max_)
        {
            const auto finish_msg = imbue(line::clear,cursor::go_col(1), finished_);
            return std::make_pair(finish_msg, false);
        }

        const auto c = spinner_++ % style_.length();
        const auto spinner_msg = imbue(line::clear,cursor::go_col(1), color_,style_.at(c), message_);

        return std::make_pair(spinner_msg, true);
    }
}}

