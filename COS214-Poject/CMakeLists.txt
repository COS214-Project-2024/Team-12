cmake_minimum_required(VERSION 3.10)
project(COS214-Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Google Test
add_subdirectory(gtests)

# Collect all source files in the `src` directory
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Add main executable with source files
add_executable(COS214-Project ${SRC_FILES})

# Link Google Test libraries to your executable
target_link_libraries(COS214-Project gtest gtest_main)
