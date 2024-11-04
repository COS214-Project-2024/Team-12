#include "gtest/gtest.h"
#include "../COS214-Poject/src/IncomeResourceProduct.h" 
#include "../COS214-Poject/src/ConstructionResourceProduct.h" 

#include "../COS214-Poject/src/ResourceFactory.h"
#include "../COS214-Poject/src/ChemicalFactory.h"
#include "../COS214-Poject/src/MetalFactory.h"
#include "../COS214-Poject/src/PlantFactory.h"
#include "../COS214-Poject/src/StoneFactory.h"

#include "../COS214-Poject/src/Gold.h"
#include "../COS214-Poject/src/Diamonds.h"
#include "../COS214-Poject/src/Oil.h"
#include "../COS214-Poject/src/Coal.h"
#include "../COS214-Poject/src/Wood.h"
#include "../COS214-Poject/src/Stone.h"
#include "../COS214-Poject/src/Steel.h"
#include "../COS214-Poject/src/Concrete.h"
#include "../COS214-Poject/src/CityComponent.h"

// Google Test Fixture for IncomeResourceProduct

class IncomeResourceProductTest : public ::testing::Test {
protected:
    Gold product{100, 50.0}; 
 
    std::string name = "Gold";
    int initialQuantity = 100;
    double initialMarketValue = 50.0;
    IncomeResourceProduct *incomeResource;

    void SetUp() override {
        // Initialize with initial values
        incomeResource = new Coal(initialQuantity, initialMarketValue);
    }

    void TearDown() override {
        // Clean up memory
        delete incomeResource;
    }
    
     // Replace with a specific derived class
     // Replace with a specific derived class
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


// Test the constructor and getters
TEST_F(IncomeResourceProductTest, ConstructorAndGetters) {
    EXPECT_EQ(incomeResource->getBuildingType(), "IncomeResourceProduct"); // Assuming a fixed return type
    EXPECT_EQ(incomeResource->getQuantity(), initialQuantity);
    EXPECT_EQ(incomeResource->getMarketValue(), initialMarketValue);
    EXPECT_EQ(incomeResource->isReadyForCollection(), false); // Assuming initial state is false
}



// Test consumeResources
TEST_F(IncomeResourceProductTest, ConsumeResources) {
    incomeResource->consumeResources(20);
    EXPECT_EQ(incomeResource->getQuantity(), initialQuantity - 20);

    // Test consuming more than available quantity (should handle gracefully)
    incomeResource->consumeResources(initialQuantity); // All should be consumed
    EXPECT_EQ(incomeResource->getQuantity(), 0);

    // Test consuming zero and negative amounts
    incomeResource->consumeResources(0);
    EXPECT_EQ(incomeResource->getQuantity(), 0);
    incomeResource->consumeResources(-10); // Ideally should not change quantity
    EXPECT_EQ(incomeResource->getQuantity(), 0);
}

// Test calculateIncome
TEST_F(IncomeResourceProductTest, CalculateIncome) {
    double expectedIncome = initialQuantity * initialMarketValue;
    EXPECT_DOUBLE_EQ(incomeResource->calculateIncome(), expectedIncome);

    // After consuming some resources
    incomeResource->consumeResources(20);
    expectedIncome = incomeResource->getQuantity() * initialMarketValue;
    EXPECT_DOUBLE_EQ(incomeResource->calculateIncome(), expectedIncome);
}

// Test replenish
TEST_F(IncomeResourceProductTest, Replenish) {
    incomeResource->replenish(50);
    EXPECT_EQ(incomeResource->getQuantity(), initialQuantity + 50);

    // Test replenishing by a negative amount (should not change quantity)
    incomeResource->replenish(-20);
    EXPECT_EQ(incomeResource->getQuantity(), initialQuantity + 50);

    // Test replenishing zero (should not change quantity)
    incomeResource->replenish(0);
    EXPECT_EQ(incomeResource->getQuantity(), initialQuantity + 50);
}

// Test displayStatus (expecting a specific output format)
// Test displayStatus (expecting a specific output format)
TEST_F(IncomeResourceProductTest, DisplayStatus) {
    // Redirect output to a string stream
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    product.displayStatus();
    
    // Restore original buffer
    std::cout.rdbuf(old);
    
    // Expected output based on the new format
    std::string expectedOutput = 
        "Resource: Coal\n"
        "Quantity: 100\n"
        "Market Value per Unit: $50.0\n"
        "Total Value: $5000.0\n\n";

    EXPECT_EQ(buffer.str(), expectedOutput);
}

// Test isReadyForCollection
TEST_F(IncomeResourceProductTest, IsReadyForCollection) {
    // Initially not ready for collection
    EXPECT_FALSE(incomeResource->isReadyForCollection());
    
    // Set as ready for collection (manipulating private attribute if accessible or add setter in class if required)
    // Expect true as output after modification
}

// Test getBuildingType
TEST_F(IncomeResourceProductTest, GetBuildingType) {
    EXPECT_EQ(incomeResource->getBuildingType(), "IncomeResourceProduct");
}


