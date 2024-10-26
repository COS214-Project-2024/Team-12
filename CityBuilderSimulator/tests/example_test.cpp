#include <gtest/gtest.h>
#include <climits>  // Added for INT_MAX
#include "project/example.h"

class ExampleTest : public ::testing::Test {
protected:
    project::Example example;
};

TEST_F(ExampleTest, AddPositiveNumbers) {
    EXPECT_EQ(example.add(2, 3), 5);
}

TEST_F(ExampleTest, AddNegativeNumbers) {
    EXPECT_EQ(example.add(-2, -3), -5);
}

TEST_F(ExampleTest, AddOverflow) {
    EXPECT_THROW(example.add(INT_MAX, 1), std::overflow_error);
}