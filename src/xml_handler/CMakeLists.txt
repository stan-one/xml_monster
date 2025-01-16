# xml_handler/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Create library for XmlHandler
add_library(xml_handler
    STATIC
        xml_handler.cpp
)

# Set include directories for this module
target_include_directories(xml_handler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(xml_handler
    PRIVATE
        tinyxml2
)
