# module_1/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Create library for Module1
add_library(module_1
    STATIC
        module_1.cpp
        module_1.hpp
)

target_include_directories(module_1
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
