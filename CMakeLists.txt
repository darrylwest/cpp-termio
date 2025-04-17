cmake_minimum_required(VERSION 3.30)  # Minimum version for CMake
project(termio VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the include directory
include_directories(include/termio)

# Create a static library from the source file
add_library(termio STATIC src/termio.cpp)

find_package(Catch2 3 REQUIRED)


# Specify the target for the tests
add_executable(termio_tests tests/termio_tests.cpp)

# Link the static library and Catch2 to the test executable
target_link_libraries(termio_tests PRIVATE termio Catch2::Catch2WithMain)

# Optionally, you can add a test command if you have CTest available
enable_testing()
add_test(NAME unit_tests COMMAND termio_tests)

