cmake_minimum_required(VERSION 3.28)  # Latest stable version as of 2024
project(termio VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Modern way to handle include directories
add_library(termio STATIC src/termio.cpp)
target_include_directories(termio PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

find_package(Catch2 3 REQUIRED)

# Specify the target for the tests
add_executable(termio_tests tests/termio_tests.cpp)

# Link the static library and Catch2 to the test executable
target_link_libraries(termio_tests PRIVATE 
    termio 
    Catch2::Catch2WithMain
)

# Enable testing
enable_testing()
add_test(NAME unit_tests COMMAND termio_tests)