//
// 2025-04-14 14:25:31 dpw
//

#include <catch2/catch_all.hpp>
#include <string>
#include <termio/termio.hpp>

TEST_CASE("Termio tests", "[wrap]") {
    using namespace termio::termio;

    const auto text = wrap("This is blue text.", Color::blue, Attr::bold);

    REQUIRE(text.contains("This is blue text."));
    REQUIRE(text.contains(to_string(Attr::bold)));
    REQUIRE(text.starts_with(to_string(Color::blue)));
    REQUIRE(text.ends_with(to_string(Color::reset)));
}

TEST_CASE("Termio tests", "[wrap][default-attr]") {
    using namespace termio::termio;

    const auto text = wrap("This is yellow text.", Color::yellow);

    REQUIRE(text.contains("This is yellow text."));
    REQUIRE(text.contains(to_string(Attr::normal)));
    REQUIRE(text.starts_with(to_string(Color::yellow)));
    REQUIRE(text.ends_with(to_string(Color::reset)));
}

TEST_CASE("Termio tests", "[attrs][bold]") {
    using namespace termio::termio;
    std::ostringstream oss;

    oss << bold() << "some text" << reset_nl();
    auto text = oss.str();

    REQUIRE(text.contains("some text"));
    REQUIRE(text.starts_with(to_string(Attr::bold)));
    REQUIRE(text.ends_with(to_string(Color::reset) + "\n"));
}

TEST_CASE("Termio tests", "[colors][bright]") {
    using namespace termio::termio;

    const auto bright_blue = to_string(Color::blue, true);

    const auto blue = to_string(Color::blue);

    REQUIRE(true);
}

TEST_CASE("Termio tests", "[colors][all-normal]") {
    using namespace termio::termio;

    REQUIRE(black() == to_string(Color::black));
    REQUIRE(red() == to_string(Color::red));
    REQUIRE(green() == to_string(Color::green));
    REQUIRE(yellow() == to_string(Color::yellow));
    REQUIRE(blue() == to_string(Color::blue));
    REQUIRE(magenta() == to_string(Color::magenta));
    REQUIRE(cyan() == to_string(Color::cyan));
    REQUIRE(white() == to_string(Color::white));
}
