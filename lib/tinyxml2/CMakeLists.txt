cmake_minimum_required(VERSION 3.10)

# Create library for tinyxml2
add_library(tinyxml2
    STATIC
        tinyxml2.cpp
)

# Set include directories for tinyxml2
target_include_directories(tinyxml2
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)