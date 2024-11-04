// #include "gtest/gtest.h"
// #include "../COS214-Poject/src//IncomeResourceProduct.h" 
// #include "../COS214-Poject/src//ConstructionResourceProduct.h" 

// #include "../COS214-Poject/src//ResourceFactory.h"
// #include "../COS214-Poject/src//ChemicalFactory.h"
// #include "../COS214-Poject/src//MetalFactory.h"
// #include "../COS214-Poject/src//PlantFactory.h"
// #include "../COS214-Poject/src//StoneFactory.h"

// #include "../COS214-Poject/src//Gold.h"
// #include "../COS214-Poject/src//Diamonds.h"
// #include "../COS214-Poject/src//Oil.h"
// #include "../COS214-Poject/src//Coal.h"
// #include "../COS214-Poject/src//Wood.h"
// #include "../COS214-Poject/src//Stone.h"
// #include "../COS214-Poject/src//Steel.h"
// #include "../COS214-Poject/src//Concrete.h"
// #include "../COS214-Poject/src//CityComponent.h"


// // Test Fixture for ConstructionResourceProduct
// class ConstructionResourceProductTest : public ::testing::Test {
// protected:
//     Concrete product{100, 20};  // Initialize with some default values
// };

// // Test constructor and getters
// TEST_F(ConstructionResourceProductTest, ConstructorAndGetters) {
//     EXPECT_EQ(product.getBuildingType(), "Construction resources");
//     EXPECT_EQ(product.getQuantity(), 100);
//     EXPECT_EQ(product.getUnitCost(), 20);
//     EXPECT_EQ(product.getTotalCost(), 100 * 20);
// }

// // Test consumeResources with a valid amount
// TEST_F(ConstructionResourceProductTest, ConsumeResource) {
//     product.ConsumeResource(30);
//     EXPECT_EQ(product.getQuantity(), 70);  // 100 - 30 = 70
// }

// // Test consumeResources with an amount exceeding the available quantity
// TEST_F(ConstructionResourceProductTest, ConsumeResourceExceedingQuantity) {
//     product.ConsumeResource(150);  // Attempt to consume more than available
//     EXPECT_EQ(product.getQuantity(), 100);  // Quantity should remain unchanged
// }

// // Test getTotalCost calculation
// TEST_F(ConstructionResourceProductTest, GetTotalCost) {
//     int expectedTotalCost = 100 * 20;
//     EXPECT_EQ(product.getTotalCost(), expectedTotalCost);

//     product.ConsumeResource(50);  // Consume some resources
//     expectedTotalCost = 50 * 20;
//     EXPECT_EQ(product.getTotalCost(), expectedTotalCost);
// }

// // Test replenish method with a positive amount
// TEST_F(ConstructionResourceProductTest, Replenish) {
//     product.replenish(50);
//     EXPECT_EQ(product.getQuantity(), 150);  // 100 + 50 = 150
// }

// // Test replenish with zero (quantity should remain the same)
// TEST_F(ConstructionResourceProductTest, ReplenishZero) {
//     product.replenish(0);
//     EXPECT_EQ(product.getQuantity(), 100);
// }

// // Test replenish with a large amount
// TEST_F(ConstructionResourceProductTest, ReplenishLargeAmount) {
//     int largeAmount = 1000;
//     product.replenish(largeAmount);
//     EXPECT_EQ(product.getQuantity(), 100 + largeAmount);
// }

// // Test displayStatus method (expecting specific output format)
// TEST_F(ConstructionResourceProductTest, DisplayStatus) {
//     std::stringstream buffer;
//     std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

//     product.displayStatus();

//     std::cout.rdbuf(old);
//     std::string expectedOutput =
//         "Resource: Concrete\n"
//         "Quantity: 100\n"
//         "Unit Cost: $20\n"
//         "Total Value: $2000\n\n";
//     EXPECT_EQ(buffer.str(), expectedOutput);
// }

// // Test isReadyForCollection with quantity below threshold
// TEST_F(ConstructionResourceProductTest, IsReadyForCollectionBelowThreshold) {
//     EXPECT_FALSE(product.isReadyForCollection());  // Quantity is 100, below 150
// }

// // Test isReadyForCollection with quantity above threshold
// TEST_F(ConstructionResourceProductTest, IsReadyForCollectionAboveThreshold) {
//     product.replenish(100);  // Increase quantity to 200
//     EXPECT_TRUE(product.isReadyForCollection());
// }

// // Test getUnitCost
// TEST_F(ConstructionResourceProductTest, GetUnitCost) {
//     EXPECT_EQ(product.getUnitCost(), 20);
// }

