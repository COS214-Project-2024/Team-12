# Set the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CitySimulator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find threading package explicitly
find_package(Threads REQUIRED)

# Define the path to the source and test directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/COS214-Poject/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

# Find all .cpp files in the source and test directories
file(GLOB SOURCES "${SRC_DIR}/*.cpp")
file(GLOB TEST_SOURCES "${TEST_DIR}/*.cpp")

# Separate main.cpp from the rest of the sources
list(REMOVE_ITEM SOURCES "${SRC_DIR}/main.cpp")

# Add the main executable target with all source files including main.cpp
add_executable(city_simulator ${SOURCES} "${SRC_DIR}/main.cpp")

# Link Threads to the main executable if necessary
target_link_libraries(city_simulator ${CMAKE_THREAD_LIBS_INIT})

# Check if gtests directory exists
if(EXISTS "${PROJECT_SOURCE_DIR}/gtests")
    # If gtests exists locally, use it
    add_subdirectory(gtests)
else()
    # If not, use FetchContent to download Google Test
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/heads/main.zip
      DOWNLOAD_EXTRACT_TIMESTAMP true
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Add the test executable with necessary test source files, without main.cpp
add_executable(runTests ${SOURCES} ${TEST_SOURCES})

# Link Google Test and Threads to the test executable
target_link_libraries(runTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})

# Enable testing
enable_testing()
add_test(NAME runTests COMMAND runTests)
