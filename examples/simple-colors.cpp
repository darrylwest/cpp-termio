//
// Created by Darryl West on 4/17/25.
//

#include <termio/termio.hpp>
#include <print>
#include <iostream>
#include <sstream>

using namespace termio::termio;

int main() {
    // using print / format to set colors
    std::puts("\nprintln text -------------------------");
    std::println("{}{}{}", green(), "Hello green World!", reset());
    std::println("{}{}{}", green(true), "Hello bright green World!", reset());
    std::println("{}{}{}", yellow(), "Hello banana!", reset());
    std::println("{}{}{}", yellow(true), "Hello bright banana!", reset());
    std::println("{}{}{}{}", magenta(true), italic(), "Hello italic magenta!", reset());

    // using wrap to set colors
    std::puts("\nWrapped text -------------------------");
    std::puts(wrap("this is a blue wrap", Color::blue).c_str());
    std::puts(wrap("this is a blue bold wrap", Color::blue, Attr::bold).c_str());
    std::puts(wrap("this is a magenta wrap", Color::cyan).c_str());
    std::puts(wrap("this is a cyan wrap", Color::magenta).c_str());
    std::puts(wrap("this is an itallic yellow wrap", Color::yellow, Attr::italic).c_str());
    std::puts(wrap("this is an white strikethrough wrap", Color::white, Attr::strikethrough).c_str());

    std::puts("\nstring stream text --------------------");
    std::ostringstream oss;
    auto show_and_clear_oss = [&oss]() {
        std::cout << oss.str() << reset_nl();
        oss.str("");
        oss.clear();
    };

    oss << green() << underline() << "underline green" << reset() << blue() << " with blue.";
    show_and_clear_oss();

    oss << red(true) << to_string(Attr::strikethrough) << "strikethrough bright red" << reset();
    show_and_clear_oss();

    return 0;
}