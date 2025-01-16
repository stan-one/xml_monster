# module_2/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Create library for Module2
add_library(csv_handler
    STATIC
        csv_handler.cpp
        csv_handler.hpp
)

# Set include directories for this module
target_include_directories(csv_handler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)