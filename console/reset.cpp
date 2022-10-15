#include <console/reset.hpp>

namespace console { namespace reset {

    const Escape all = {"\033[0m"};
    const Escape color = {"\033[39m"};
    const Escape background = {"\033[49m"};
    const Escape border = {"\033[22m \033[39m"};

    const Escape bold = {"\033[22m"};
    const Escape faint = {"\033[22m"};
    const Escape italics = {"\033[23m"};
    const Escape underline = {"\033[24m"};
    const Escape blink = {"\033[25m"};
    const Escape invert = {"\033[27m"};
    const Escape invisible = {"\033[28m"};
    const Escape strike = {"\033[29m"};

}}
