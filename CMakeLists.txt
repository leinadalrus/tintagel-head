cmake_minimum_required(VERSION 3.13)  # CMake version check
project(tintagel_head)                # Create project
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp)

find_package(raylib REQUIRED)
find_package(ZLIB REQUIRED)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(tintagel_head ${SOURCE_FILES})
