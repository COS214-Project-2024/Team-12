#include <gtest/gtest.h>
#include "../src/City/CityComponent/Resources/IncomeResourceProduct.h" 
#include "../src/City/CityComponent/Resources/ConstructionResourceProduct.h" 
#include "../src/City/CityComponent/Resources/ChemicalFactory.h"
#include "../src/City/CityComponent/Resources/MetalFactory.h"
#include "../src/City/CityComponent/Resources/PlantFactory.h"
#include "../src/City/CityComponent/Resources/StoneFactory.h"
#include "../src/City/CityComponent/Resources/Gold.h"
#include "../src/City/CityComponent/Resources/Diamonds.h"
#include "../src/City/CityComponent/Resources/Oil.h"
#include "../src/City/CityComponent/Resources/Coal.h"
#include "../src/City/CityComponent/Resources/Wood.h"
#include "../src/City/CityComponent/Resources/Stone.h"
#include "../src/City/CityComponent/Resources/Steel.h"
#include "../src/City/CityComponent/Resources/Concrete.h"
#include "../src/City/CityComponent/CityComponent.h"

// Google Test Fixture for IncomeResourceProduct

class IncomeResourceProductTest : public ::testing::Test {
protected:
    Gold product{100, 50.0};  // Replace with a specific derived class
};


// Test for calculateIncome
TEST_F(IncomeResourceProductTest, CalculateIncome) {
    double expectedIncome = 100 * 50.0;
    EXPECT_DOUBLE_EQ(product.calculateIncome(), expectedIncome);
}

// Test for getQuantity
TEST_F(IncomeResourceProductTest, GetQuantity) {
    EXPECT_EQ(product.getQuantity(), 100);
}

// Test for getMarketValue
TEST_F(IncomeResourceProductTest, GetMarketValue) {
    EXPECT_DOUBLE_EQ(product.getMarketValue(), 50.0);
}

// Test for isReadyForCollection (initial state should be false)
TEST_F(IncomeResourceProductTest, InitialReadyForCollection) {
    EXPECT_FALSE(product.isReadyForCollection());
}

// Test for consumeResources (valid consumption)
TEST_F(IncomeResourceProductTest, ConsumeResources) {
    product.consumeResources(30);
    EXPECT_EQ(product.getQuantity(), 70);  // 100 - 30 = 70
}

// Test for consumeResources (invalid consumption exceeding quantity)
TEST_F(IncomeResourceProductTest, ConsumeResourcesExceedingQuantity) {
    product.consumeResources(150);  // More than available quantity
    EXPECT_EQ(product.getQuantity(), 100);  // Quantity should remain the same
}

// Test for replenish
TEST_F(IncomeResourceProductTest, Replenish) {
    product.replenish(50);
    EXPECT_EQ(product.getQuantity(), 150);  // 100 + 50 = 150
    EXPECT_TRUE(product.isReadyForCollection());  // Should now be ready for collection
}

// Test for isReadyForCollection after resources have been replenished and consumed
TEST_F(IncomeResourceProductTest, ReadyForCollectionAfterReplenishAndConsume) {
    product.replenish(50);  // Ready for collection should be true
    product.consumeResources(50);  // Consuming resources should maintain the ready state as true if quantity > 0
    EXPECT_FALSE(product.isReadyForCollection());
}



TEST_F(IncomeResourceProductTest, CalculateIncomeWithZeroValues) {
    Diamonds zeroProduct( 0, 0.0);
    EXPECT_DOUBLE_EQ(zeroProduct.calculateIncome(), 0.0);
}


TEST_F(IncomeResourceProductTest, ConsumeResourcesWithZeroAmount) {
    product.consumeResources(0);
    EXPECT_EQ(product.getQuantity(), 100);
}

TEST_F(IncomeResourceProductTest, ConsumeResourcesExactQuantity) {
    product.consumeResources(100);  // Consumes exactly all resources
    EXPECT_EQ(product.getQuantity(), 0);
    EXPECT_FALSE(product.isReadyForCollection());
}



TEST_F(IncomeResourceProductTest, ReadyForCollectionBecomesFalseWhenQuantityIsZero) {
    product.consumeResources(100);  // Set quantity to zero
    EXPECT_FALSE(product.isReadyForCollection());
}

TEST_F(IncomeResourceProductTest, ReplenishWithZeroAmount) {
    product.replenish(0);
    EXPECT_EQ(product.getQuantity(), 100);  // Should remain unchanged
    EXPECT_FALSE(product.isReadyForCollection());  // No change in collection status
}

TEST_F(IncomeResourceProductTest, ReplenishWithLargeAmount) {
    int largeAmount = 1000000;
    product.replenish(largeAmount);
    EXPECT_EQ(product.getQuantity(), 100 + largeAmount);
    EXPECT_TRUE(product.isReadyForCollection());
}






// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();  // Runs all tests and returns the result
// }


