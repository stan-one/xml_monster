# Root CMakeLists.txt (in the project root directory)
cmake_minimum_required(VERSION 3.10)
project(ModuleProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for each module
add_subdirectory(src)
add_subdirectory(lib/tinyxml2)

# Create the main executable
add_executable(main main.cpp)

# Link the modules to the main executable
target_link_libraries(main
    PRIVATE
        module_1
        module_2
        xml_handler
)