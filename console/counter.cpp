#include <console/counter.hpp>

namespace console { namespace progress {
    
    Counter::Counter(const uint64_t max)
        : ProgressIndicator(max)
    {
    }

    auto Counter::bracket_color(const ConsoleColor& color) -> Counter&
    {
        bracket_color_ = color;
        return *this;
    }

    auto Counter::left(const std::string& l) -> Counter&
    {
        left_ = l;
        return *this;
    }

    auto Counter::right(const std::string& r) -> Counter&
    {
        right_ = r;
        return *this;
    }

    auto Counter::count_color(const ConsoleColor& color) -> Counter&
    {
        count_color_ = color;
        return *this;
    }

    auto Counter::total_color(const ConsoleColor& color) -> Counter&
    {
        total_color_ = color;
        return *this;
    }

    auto Counter::message_color(const ConsoleColor& color) -> Counter&
    {
        message_color_ = color;
        return *this;
    }

    auto Counter::message(const std::string& msg) -> Counter&
    {
        message_ = msg;
        return *this;
    }

    auto Counter::before_update(const Escape& escapeSeq) -> Counter&
    {
        before_ = escapeSeq;
        return *this;
    }
    
    auto Counter::on_finish(const std::string& msg) -> Counter&
    {
        finished_ = msg;
        return *this;
    }

    auto Counter::update(const uint64_t by_count) -> std::pair<std::string, Status>
    {
        count_ += by_count;
        
        const auto done = done_;
        done_ = count_ >= max_;
        count_ = done_ ? max_ : count_;

        const auto msg = imbue(
              before_
            , message_
            , bracket_color_
            , left_
            , count_color_
            , count_
            , bracket_color_
            , "/"
            , total_color_
            , max_
            , bracket_color_
            , right_);

        return done 
            ? std::make_pair(finished_, Status::Complete)
            : std::make_pair(msg, Status::Continue);
    }

}}
