#include <gtest/gtest.h>
#include "/IncomeResourceProduct.cpp"  // Include the existing implementation

// Google Test Fixture for IncomeResourceProduct
class IncomeResourceProductTest : public ::testing::Test {
protected:
    IncomeResourceProduct product{"Gold", 100, 50.0};  // Initialize an instance for testing
};

// Test cases
TEST_F(IncomeResourceProductTest, CalculateIncome) {
    double expectedIncome = 100 * 50.0;
    EXPECT_DOUBLE_EQ(product.calculateIncome(), expectedIncome);
}

TEST_F(IncomeResourceProductTest, GetQuantity) {
    EXPECT_EQ(product.getQuantity(), 100);
}

TEST_F(IncomeResourceProductTest, GetMarketValue) {
    EXPECT_DOUBLE_EQ(product.getMarketValue(), 50.0);
}

TEST_F(IncomeResourceProductTest, GetTaxRevenue) {
    double expectedTaxRevenue = 100 * 50.0 * 0.1;
    EXPECT_DOUBLE_EQ(product.getTaxRevenue(), expectedTaxRevenue);
}
