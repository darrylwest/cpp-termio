//
// Created by Darryl West on 4/17/25.
//

#include <termio/termio.hpp>
#include <print>

using namespace termio::termio;

int main() {
    std::println("{}{}{}", green(true), "Hello bright green World!", reset());
    std::println("{}{}{}", yellow(), "Hello banana!", reset());
    std::println("{}{}{}", yellow(true), "Hello bright banana!", reset());

    return 0;
}