#include <console/console.hpp>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using namespace console;

int main() 
{
	std::cout 
		<< "-----------------------------------------\n"
		<< color::black << "black" << reset::all << "\n" 
		<< color::red << "red" << reset::all << "\n" 
		<< color::green << "green" << reset::all << "\n" 
		<< color::orange << "orange" << reset::all << "\n" 
		<< color::blue << "blue" << reset::all << "\n" 
		<< color::purple << "purple" << reset::all << "\n" 
		<< color::cyan << "cyan" << reset::all << "\n" 
		<< color::grey << "grey" << reset::all << "\n" 
		<< color::dark_grey << "dark gray" << reset::all << "\n" 
		<< color::light_red << "light red" << reset::all << "\n" 
		<< color::light_green << "light green" << reset::all << "\n" 
		<< color::yellow << "yellow" << reset::all << "\n" 
		<< color::light_blue << "light blue" << reset::all << "\n" 
		<< color::light_purple << "light purple" << reset::all << "\n" 
		<< color::light_cyan << "light cyan" << reset::all << "\n" 
		<< color::white << "white" << reset::all << "\n" 
		<< "-----------------------------------------\n"

		<< "\n"

		<< "-----------------------------------------\n"
		<< color::bold::black << "bold black" << reset::all << "\n"
		<< color::bold::red << "bold red" << reset::all << "\n"
		<< color::bold::green << "bold green" << reset::all << "\n"
		<< color::bold::orange << "bold orange" << reset::all << "\n"
		<< color::bold::blue << "bold blue" << reset::all << "\n"
		<< color::bold::purple << "bold purple" << reset::all << "\n"
		<< color::bold::cyan << "bold cyan" << reset::all << "\n"
		<< color::bold::grey << "bold grey" << reset::all << "\n"
		<< "-----------------------------------------\n"

		<< "\n"

		<< "-----------------------------------------\n"
		<< background::black << "black background" << reset::all << "\n"
		<< background::red << "red background" << reset::all << "\n"
		<< background::green << "green background" << reset::all << "\n"
		<< background::orange << "orange background" << reset::all << "\n"
		<< background::cyan << "cyan background" << reset::all << "\n"
		<< background::purple << "purple background" << reset::all << "\n"
		<< background::blue << "blue background" << reset::all << "\n"
		<< background::grey << "grey background" << reset::all << "\n"
		<< background::dark_grey << "dark grey background" << reset::all << "\n"
		<< background::light_red << "light red background" << reset::all << "\n"
		<< background::light_green << "light green background" << reset::all << "\n"
		<< background::yellow << "yellow background" << reset::all << "\n"
		<< background::light_blue << "light blue background" << reset::all << "\n"
		<< background::light_purple << "light purple background" << reset::all << "\n"
		<< background::light_cyan << "light cyan background" << reset::all << "\n"
		<< background::white << "white background" << reset::all << "\n"
		<< "-----------------------------------------\n"

		<< "\n"

		<< "-----------------------------------------\n"
		<< style::bold << "bold" << reset::all << "\n"
		<< style::faint << "faint" << reset::all << "\n"
		<< style::italics << "italics" << reset::all << "\n"
		<< style::underline << "underline" << reset::all << "\n"
		<< style::blink << "blink" << reset::all << "\n"
		<< style::invert << "invert" << reset::all << "\n"
		<< style::invisible << "invisible" << reset::all << "\n"
		<< style::strike << "strike" << reset::all << "\n"
		<< style::underline_thick << "underline thick" << reset::all << "\n"
		<< "-----------------------------------------\n"

		<< "\n"

		<< "-----------------------------------------\n"
		<< imbue(color::rgb(100,50,10), style::bold, "bold brown") << "\n"
		<< imbue(color::rgb(10,50,200), style::bold, style::underline, "bold underline blue") << "\n"
		<< imbue(color::bold::green, style::underline, style::blink, "bold underline blinking green") << "\n"
		<< "-----------------------------------------\n"

		<< "\n"

		<< "-----------------------------------------\n"
		<< cursor::right(10) << "r*" << "\n"
		<< cursor::right(10) << cursor::left(4) << "l*" << "\n"
		<< cursor::up(6) << "u*" << "\n"
		<< cursor::down(4) << "d*" << "\n"
		<< cursor::hide << cursor::show << "\n"
		<< "-----------------------------------------\n"
	;

	std::cout 
		<< cursor::go_to(10, 40) << "yo yo" << cursor::go_to(40, 1) << "\n"
		<< cursor::go_col(20) << "yo yo" << "\n";
	
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << screen::clear;
	std::cout << "hello hello";
	std::this_thread::sleep_for(std::chrono::seconds(2));	
	std::cout << line::clear << cursor::home;
	std::cout << "goodbye goodbye" << "\n";

	std::cout << "hello hello";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << line::clear_before << "\n";

	std::cout << "the quick brown fox jumped over the log";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << cursor::go_col(16) << line::clear_after << "\n";

	std::cout << "more stuff\nand more stuff\nand more\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << screen::clear_above;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "more stuff\nand more stuff\nand more\n"
		<< cursor::up(2) << screen::clear_below;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
