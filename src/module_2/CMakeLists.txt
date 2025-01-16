# module_2/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Create library for Module2
add_library(module_2
    STATIC
        module_2.cpp
        module_2.hpp
)

# Set include directories for this module
target_include_directories(module_2
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)