//
// 2025-04-14 14:25:31 dpw
//

#include <iostream>
#include <sstream>
#include <string>
#include <termio/termio.hpp>

namespace termio::termio {

    // Convert color to ANSI code
    std::string to_string(Color c, bool bright) {
        switch (c) {
            case Color::black:
                return bright ? "\033[1;30m" : "\033[0;30m";
            case Color::red:
                return bright ? "\033[1;31m" : "\033[0;31m";
            case Color::green:
                return bright ? "\033[1;32m" : "\033[0;32m";
            case Color::yellow:
                return bright ? "\033[1;33m" : "\033[0;33m";
            case Color::blue:
                return bright ? "\033[1;34m" : "\033[0;34m";
            case Color::magenta:
                return bright ? "\033[1;35m" : "\033[0;35m";
            case Color::cyan:
                return bright ? "\033[1;36m" : "\033[0;36m";
            case Color::white:
                return bright ? "\033[1;37m" : "\033[0;37m";
            default:;
                // default to reset
                return "\033[0m";
        }
    }

    auto to_string(Attr a) -> std::string {
        switch (a) {
            case Attr::normal:
                return "\033[0m";
            case Attr::bold:
                return "\033[1m";
            case Attr::faint:
                return "\033[2m";
            case Attr::italic:
                return "\033[3m";
            case Attr::underline:
                return "\033[4m";
            case Attr::blink:
                return "\033[5m";
            case Attr::rapid_blink:
                return "\033[6m";
            case Attr::reverse:
                return "\033[7m";
            case Attr::hidden:
                return "\033[8m";
            case Attr::strikethrough:
                return "\033[9m";
        }

        // default to reset attr
        return "\033[0m";
    }

    // Color Overload << for easier use
    auto operator<<(std::ostream& os, Color c) -> std::ostream& { return os << to_string(c); }

    // Attr Overload << for easier use
    auto operator<<(std::ostream& os, Attr a) -> std::ostream& { return os << to_string(a); }

    const std::string wrap(const std::string& s, const Color& c, const Attr& a) {
        std::stringstream ss;

        ss << c << a << s << Color::reset;
        return ss.str();
    }

    auto normal() -> const std::string { return to_string(Attr::normal); }
    auto bold() -> const std::string { return to_string(Attr::bold); }
    auto italic() -> const std::string { return to_string(Attr::italic); }
    auto underline() -> const std::string { return to_string(Attr::underline); }
    // auto blink() -> const std::string { return to_string(Attr::rapid_blink); }
    auto reverse() -> const std::string { return to_string(Attr::reverse); }
    auto strikethrough() -> const std::string { return to_string(Attr::strikethrough); }

    auto black(bool bright) -> const std::string { return to_string(Color::black, bright); }
    auto red(bool bright) -> const std::string { return to_string(Color::red, bright); }
    auto green(bool bright) -> const std::string { return to_string(Color::green, bright); }
    auto yellow(bool bright) -> const std::string { return to_string(Color::yellow, bright); }
    auto blue(bool bright) -> const std::string { return to_string(Color::blue, bright); }
    auto magenta(bool bright) -> const std::string { return to_string(Color::magenta, bright); }
    auto cyan(bool bright) -> const std::string { return to_string(Color::cyan, bright); }
    auto white(bool bright) -> const std::string { return to_string(Color::white, bright); }
    auto reset() -> const std::string { return to_string(Color::reset); }
    auto reset_nl() -> const std::string { return to_string(Color::reset) + "\n"; }

}  // namespace termio::termio
