cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Include directories
include_directories(src)       # Add src for main application code
include_directories(tests)     # Add tests for unit tests

# Add Google Test as a subdirectory with the new folder name 'gtests'
add_subdirectory(gtests)
include_directories(gtests/googletest/include)

# Main application executable
add_executable(MyProject src/main.cpp)   # Add main application files

# Test executable
add_executable(MyTests tests/NPCManagerTests.cpp tests/ReactingNPCTests.cpp tests/NPCStatesTests.cpp)  # Add all test files

# Link Google Test to the test executable
target_link_libraries(MyTests gtest gtest_main)
