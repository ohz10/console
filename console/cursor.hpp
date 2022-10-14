#pragma once
#include <console/escape.hpp>
#include <string>

namespace console { namespace cursor {

	auto up(const uint16_t rows) -> std::string;
	auto down(const uint16_t rows) -> std::string;
	auto left(const uint16_t columns) -> std::string;
	auto right(const uint16_t columns) -> std::string;

	auto go_to(const uint16_t row, const uint16_t column) -> std::string;
	auto go_col(const uint16_t column) -> std::string;

	extern const Escape hide;
	extern const Escape show;

	extern const Escape home;
}}

