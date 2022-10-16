#include <console/console.hpp>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace console;
using namespace console::progress;

auto file_counter()
{
    cursor::ScopedHider hide(std::cout);
    
    const auto tick = std::chrono::milliseconds(1);
    auto ticker = Counter(1000)
        .count_color({color::grey})
        .total_color({color::dark_grey})
        .message(imbue(color::light_cyan, "files downloaded... "))
        .on_finish(imbue(
              line::clear
            , cursor::go_col(1)
            , color::cyan
            , "complete."
            , "\n"));

    std::string m;
    Status status;
    
    do {
        std::tie(m, status) = ticker.update(3);
        std::cout << m << std::flush;
        
        if(ticker.count() % 10)
        {
            std::this_thread::sleep_for(tick);
        }
    } while(status == Status::Continue);
}

auto stock_spinner()
{
    cursor::ScopedHider hide(std::cout);
    
    const auto tick = std::chrono::milliseconds(100);
    auto spinner = Spinner(2000)
        .color({color::white})
        .message(imbue(ConsoleColor{color::blue}, " fetching data"))
        .on_finish(imbue(
              line::clear
            , cursor::go_col(1)
            , ConsoleColor{color::white}
            , "complete.", "\n"));

    std::string m;
    Status status;

    do {
        std::tie(m, status) = spinner.update(100);
        std::cout << m << std::flush;
    
        std::this_thread::sleep_for(tick);
    } while(status == Status::Continue);
}

auto bouncing_spinner()
{
    cursor::ScopedHider hide(std::cout);
    
    const auto tick = std::chrono::milliseconds(150);
    const std::vector messages = {" bounce", " bounce bounce", " all day long"};
    uint8_t mc = 1;

    uint16_t perc = 100 / messages.size();
    std::string m;
    Status status;

    auto spinner = Spinner(2000)
        .style("*-.")
        .message(messages.at(0))
        .on_finish(imbue(
              line::clear
            , cursor::go_col(1)
            , ConsoleColor{color::bold::green}
            , "complete.", "\n"));

    do {
        std::tie(m, status) = spinner.update(100);
        std::cout << m << std::flush;
        
        if(spinner.percent() >= perc)
        {
            perc = spinner.percent() + (100 / messages.size()); 
            spinner.message(messages.at(mc++ % messages.size()));
        }

        std::this_thread::sleep_for(tick);
    } while(status == Status::Continue);
}

auto stock_bar()
{
    cursor::ScopedHider hide(std::cout);
    
    const auto tick = std::chrono::milliseconds(100);
    std::string m;
    Status status;
    
    auto bar = ProgressBar(40, 2000)
        .color({color::purple})
        .bracket_color({color::light_blue})
        .message(imbue(ConsoleColor{color::light_purple}, " extracting files..."))
        .on_finish(imbue(
              cursor::go_col(44)
            , line::clear_after
            , ConsoleColor{color::bold::purple}
            , "complete."
            , "\n"));

    do {
        std::tie(m, status) = bar.update(100);
        std::cout << m << std::flush;
        
        std::this_thread::sleep_for(tick);
    } while(status == Status::Continue);
}

int main()
{
    file_counter();
    stock_spinner();
    bouncing_spinner();
    stock_bar();
}
