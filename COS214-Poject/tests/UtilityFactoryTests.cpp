#include "gtest/gtest.h"
#include "../src/UtilityFactory.h"

// Test that UtilityFactory returns a correct instance type
TEST(UtilityFactoryTest, ReturnsCorrectInstanceType) {
    UtilityFactory factory;
    auto powerPlant = factory.getUtility("PowerPlant");
    auto waterSupply = factory.getUtility("WaterSupply");
    auto wasteManagement = factory.getUtility("WasteManagement");
    auto sewageSystem = factory.getUtility("SewageSystem");

    EXPECT_NE(powerPlant, nullptr);
    EXPECT_NE(waterSupply, nullptr);
    EXPECT_NE(wasteManagement, nullptr);
    EXPECT_NE(sewageSystem, nullptr);

    EXPECT_EQ(powerPlant->getName(), "PowerPlant");
    EXPECT_EQ(waterSupply->getName(), "WaterSupply");
    EXPECT_EQ(wasteManagement->getName(), "WasteManagement");
    EXPECT_EQ(sewageSystem->getName(), "SewageSystem");
}

// Test that UtilityFactory returns the same instance for the same type
TEST(UtilityFactoryTest, ReusesExistingInstance) {
    UtilityFactory factory;
    auto firstInstance = factory.getUtility("PowerPlant");
    auto secondInstance = factory.getUtility("PowerPlant");

    // Check that both instances are actually the same object (flyweight pattern)
    EXPECT_EQ(firstInstance, secondInstance);
}

// Test handling of invalid utility type
TEST(UtilityFactoryTest, InvalidUtilityType) {
    UtilityFactory factory;
    try {
        auto unknownUtility = factory.getUtility("UnknownType");
        FAIL() << "Expected std::out_of_range for invalid utility type";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ(e.what(), "Invalid utility type");  // Ensure correct exception and message
    } catch (...) {
        FAIL() << "Expected std::out_of_range for invalid utility type";
    }
}

// Test that each utility's properties are initialized correctly
TEST(UtilityFactoryTest, UtilityPropertiesAreCorrect) {
    UtilityFactory factory;

    auto powerPlant = factory.getUtility("PowerPlant");
    EXPECT_EQ(powerPlant->getCost(), 10000.0);
    EXPECT_EQ(powerPlant->getCapacity(), 100);
    EXPECT_EQ(powerPlant->getEffectRadius(), 20.0);
    EXPECT_EQ(powerPlant->getResourceNeeds().at("Steel"), 150);
    EXPECT_EQ(powerPlant->getResourceNeeds().at("Copper"), 50);
    EXPECT_EQ(powerPlant->getResourceNeeds().at("Fuel"), 100);

    auto waterSupply = factory.getUtility("WaterSupply");
    EXPECT_EQ(waterSupply->getCost(), 5000.0);
    EXPECT_EQ(waterSupply->getCapacity(), 80);
    EXPECT_EQ(waterSupply->getEffectRadius(), 15.0);
    EXPECT_EQ(waterSupply->getResourceNeeds().at("Steel"), 100);
    EXPECT_EQ(waterSupply->getResourceNeeds().at("Concrete"), 200);

    auto wasteManagement = factory.getUtility("WasteManagement");
    EXPECT_EQ(wasteManagement->getCost(), 7000.0);
    EXPECT_EQ(wasteManagement->getCapacity(), 90);
    EXPECT_EQ(wasteManagement->getEffectRadius(), 18.0);
    EXPECT_EQ(wasteManagement->getResourceNeeds().at("Brick"), 100);
    EXPECT_EQ(wasteManagement->getResourceNeeds().at("Steel"), 80);

    auto sewageSystem = factory.getUtility("SewageSystem");
    EXPECT_EQ(sewageSystem->getCost(), 6000.0);
    EXPECT_EQ(sewageSystem->getCapacity(), 85);
    EXPECT_EQ(sewageSystem->getEffectRadius(), 17.0);
    EXPECT_EQ(sewageSystem->getResourceNeeds().at("Concrete"), 150);
    EXPECT_EQ(sewageSystem->getResourceNeeds().at("Steel"), 70);
}
