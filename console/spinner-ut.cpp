#include <console/console.hpp>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace console;

auto stock_spinner()
{
	auto spinner = spinners::Spinner(2000)
		.color(color::green)
		.message(imbue(color::red, " fetching data"))
		.on_finish(imbue(color::white, "complete."));

	std::cout << cursor::hide;
	for(uint16_t i = 0; i < 3000; ++i)
	{
		const auto [m, cont] = spinner.update(100);
		std::cout << m << std::flush;

		if(!cont) 
		{
			std::cout << "\n";
			break;
		}
	
		std::this_thread::sleep_for(spinners::tick);
	}
	std::cout << cursor::show;
}

auto bouncing_spinner()
{
	const std::vector messages = {" bounce", " bounce bounce", " all day long"};
	uint8_t mc = 0;

	auto spinner = spinners::Spinner(2000)
		.style("*-.")
		.message(messages.at(0))
		.on_finish("complete");

	std::cout << cursor::hide;
	for(uint16_t i = 0; i < 3000; ++i)
	{
		const auto [m, cont] = spinner.update(100);
		std::cout << m << std::flush;

		std::cout << imbue(cursor::up(1),line::clear,cursor::go_col(1),"percent: ", spinner.percent(), "\n");

		if(!cont) 
		{ 
			std::cout << "\n"; 
			break; 
		}

		std::this_thread::sleep_for(spinners::tick);

		if(i % 1000)
		{
			spinner.message(messages.at(mc++ % messages.size()));
		}
	}
	std::cout << cursor::show;
}

int main()
{
	stock_spinner();
	bouncing_spinner();
}
