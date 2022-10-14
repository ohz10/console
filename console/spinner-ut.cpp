#include <console/console.hpp>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace console;

auto stock_spinner()
{
	const auto tick = std::chrono::milliseconds(100);
	auto spinner = spinners::Spinner(2000)
		.color(color::green)
		.message(imbue(color::red, " fetching data"))
		.on_finish(imbue(color::white, "complete.", "\n"));

	std::cout << cursor::hide;

	std::string m;
	bool cont;

	do {
		std::tie(m, cont) = spinner.update(100);
		std::cout << m << std::flush;
	
		std::this_thread::sleep_for(tick);
	} while(cont);

	std::cout << cursor::show;
}

auto bouncing_spinner()
{
	const auto tick = std::chrono::milliseconds(150);
	const std::vector messages = {" bounce", " bounce bounce", " all day long"};
	uint8_t mc = 1;

	uint16_t perc = 100 / messages.size();
	std::string m;
	bool cont;

	auto spinner = spinners::Spinner(2000)
		.style("*-.")
		.message(messages.at(0))
		.on_finish("complete.\n");

	std::cout << cursor::hide;

	do {
		std::tie(m, cont) = spinner.update(100);
		std::cout << m << std::flush;
		
		if(spinner.percent() >= perc)
		{
			perc = spinner.percent() + (100 / messages.size()); 
			spinner.message(messages.at(mc++ % messages.size()));
		}

		std::this_thread::sleep_for(tick);
	} while(cont);
	std::cout << cursor::show;
}

int main()
{
	stock_spinner();
	bouncing_spinner();
}
