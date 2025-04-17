//
// 2025-04-14 14:25:31 dpw
//

#pragma once

#include <iostream>
#include <string>

namespace termio::termio {
    constexpr auto VERSION = "0.5.1";
    constexpr bool BRIGHT = true;

    // Enum for basic colors
    enum class Color {
        black = 0,
        red = 1,
        green = 2,
        yellow = 3,
        blue = 4,
        magenta = 5,
        cyan = 6,
        white = 7,
        reset = 9
    };

    // Enum for text attributes
    enum class Attr {
        normal = 0,
        bold = 1,
        faint = 2,
        italic = 3,
        underline = 4,
        blink = 5,
        rapid_blink = 6,
        reverse = 7,
        hidden = 8,
        strikethrough = 9,
        // bright = 60  // Not a standard attribute, but a logical addition.
    };

    // Convert color to ANSI code; set bright to true; default is false
    std::string to_string(Color c, bool bright = false);

    // convert the attribute to a ANSI code string
    std::string to_string(Attr a);

    // Color Overload << for easier use
    std::ostream& operator<<(std::ostream& os, Color c);

    // Attr Overload << for easier use
    std::ostream& operator<<(std::ostream& os, Attr a);

    auto wrap(const std::string& s, const Color& c, const Attr& a = Attr::normal) -> const std::string;
    auto normal() -> const std::string;
    auto bold() -> const std::string;
    auto italic() -> const std::string;
    auto underline() -> const std::string;

    auto black(bool bright = false) -> const std::string;
    auto red(bool bright = false) -> const std::string;
    auto green(bool bright = false) -> const std::string;
    auto yellow(bool bright = false) -> const std::string;
    auto blue(bool bright = false) -> const std::string;
    auto magenta(bool bright = false) -> const std::string;
    auto cyan(bool bright = false) -> const std::string;
    auto white(bool bright = false) -> const std::string;
    auto reset() -> const std::string;
    auto reset_nl() -> const std::string;

}  // namespace termio::termio
