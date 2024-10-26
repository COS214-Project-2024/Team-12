# Create the test executable
add_executable(unit_tests
    example_test.cpp
)

# Link against Google Test and your library
target_link_libraries(unit_tests
    PRIVATE
        citybuilder_lib
        GTest::gtest_main
)

# This is important! It enables test discovery
include(GoogleTest)
gtest_discover_tests(unit_tests)