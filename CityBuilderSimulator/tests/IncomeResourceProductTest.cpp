#include <gtest/gtest.h>
#include "../src/City/CityComponent/Resources/IncomeResourceProduct.cpp"  // Existing implementation
#include "../src/City/CityComponent/Resources/ChemicalFactory.cpp"
#include "../src/City/CityComponent/Resources/MetalFactory.cpp"
#include "../src/City/CityComponent/Resources/PlantFactory.cpp"
#include "../src/City/CityComponent/Resources/StoneFactory.cpp"
#include "../src/City/CityComponent/Resources/Gold.cpp"
#include "../src/City/CityComponent/Resources/Diamonds.cpp"
#include "../src/City/CityComponent/Resources/Oil.cpp"
#include "../src/City/CityComponent/Resources/Coal.cpp"
#include "../src/City/CityComponent/Resources/Wood.cpp"
#include "../src/City/CityComponent/Resources/Stone.cpp"
#include "../src/City/CityComponent/Resources/Steel.cpp"
#include "../src/City/CityComponent/Resources/Concrete.cpp"
#include "../src/City/CityComponent/CityComponent.h"

// Google Test Fixture for IncomeResourceProduct

class IncomeResourceProductTest : public ::testing::Test {
protected:
    Gold product{100, 50.0};  // Replace with a specific derived class
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



// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();  // Runs all tests and returns the result
// }