cmake_minimum_required(VERSION 3.13)  # CMake version check
project(core_boilerplate)               # Create project
set_property(TARGET tgt PROPERTY C_STANDARD 99)         # Enable C99 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES ./core.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(core_boilerplate ${SOURCE_FILES})