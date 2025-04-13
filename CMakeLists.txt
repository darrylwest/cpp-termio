# CMakeLists.txt
cmake_minimum_required(VERSION 3.30) # Or higher

# Project name
project(ColorFormatterLibrary)

# Enable C++11 or higher
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Useful for IDE integration and static analysis tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Check for C++23 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++23" COMPILER_SUPPORTS_CXX23)
if(NOT COMPILER_SUPPORTS_CXX23)
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++23 support.")
endif()

# Include directories for headers
include_directories(include)

# Source files
set(COLOR_SRC
    src/colors.cpp
)

# Create the library
add_library(color_formatter ${COLOR_SRC})

# Define a target for the library's header files (Modern CMake)
#  -  This creates an interface library, which doesn't produce any build output
add_library(color_formatter_headers INTERFACE)

#  -  Specify the include directories for the header files
target_include_directories(color_formatter_headers
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/term
)

#  -  Link the interface library to the color_formatter library
target_link_libraries(color_formatter
    PUBLIC
    color_formatter_headers
)

# Add a subdirectory for tests
add_subdirectory(tests)


