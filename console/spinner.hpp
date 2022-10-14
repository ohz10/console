#pragma once
#include <console/escape.hpp>

#include <chrono>
#include <cstdint>
#include <string>
#include <utility>

namespace console { namespace spinners {

	class Spinner
	{
	public:
		Spinner(const uint64_t max);

		auto style(const std::string& chars) -> Spinner&;
		auto color(const Escape& color) -> Spinner&;
		auto message(const std::string& msg) -> Spinner&;
		auto on_finish(const std::string& msg) -> Spinner&;

	public:
		// returns the string to print and whether the spinner is done
		auto update(const uint64_t by_count) -> std::pair<std::string, bool>;

		auto count() const -> uint64_t { return update_count_; }
		auto max() const -> uint64_t { return max_; }

		auto percent() const -> uint16_t {
			const double perc = 100.0 * ((double)update_count_ / (double)max_);
			return perc;
		}

	private:
		std::string style_ = "|/-\\";
		std::string message_ = "";
		std::string finished_ = "";

		Escape color_ = "";

		const uint64_t max_;
		uint64_t update_count_ = 0;
		uint8_t spinner_ = 0;
	};
}}

