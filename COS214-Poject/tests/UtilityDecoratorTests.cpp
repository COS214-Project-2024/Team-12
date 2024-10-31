#include "gtest/gtest.h"
#include "../src/UtilityDecorator.h"
#include "../src/MockCityComposite.h"
#include "../src/MockUtility.h"

class UtilityDecoratorTest : public ::testing::Test {
protected:
    void SetUp() override {
        player = std::make_unique<MockCityComposite>("Test City", 1000.0);
        baseUtility = std::make_unique<MockUtility>(
            "TestUtility", 
            500.0,      // cost
            50,         // capacity
            15.0,       // effectRadius
            true,       // operational
            1,          // level
            20,         // resourceConsumption
            std::map<std::string, int>{{"Steel", 100}}
        );
    }

    std::unique_ptr<MockCityComposite> player;
    std::unique_ptr<MockUtility> baseUtility;
};

TEST_F(UtilityDecoratorTest, InitializationSetsCorrectValues) {
    UtilityDecorator decorator(std::make_unique<MockUtility>(*baseUtility), player.get());
    
    EXPECT_EQ(decorator.getName(), "TestUtility");
    EXPECT_EQ(decorator.getCost(), 500.0);
    EXPECT_EQ(decorator.getCapacity(), 50);
    EXPECT_EQ(decorator.getEffectRadius(), 15.0);
    EXPECT_EQ(decorator.getLevel(), 1);
    EXPECT_EQ(decorator.getResourceConsumption(), 20);
    EXPECT_EQ(decorator.getUpgradeCost(), 500.0 * 0.2);
}

TEST_F(UtilityDecoratorTest, ConnectSetsOperationalStatusBasedOnDistance) {
    UtilityDecorator decorator(std::make_unique<MockUtility>(*baseUtility), player.get());
    
    // Test within range
    decorator.connect(10.0);
    EXPECT_TRUE(decorator.getOperationalStatus()) << "Should be operational within effect radius";
    
    // Test at boundary
    decorator.connect(15.0);
    EXPECT_TRUE(decorator.getOperationalStatus()) << "Should be operational at effect radius boundary";
    
    // Test out of range
    decorator.connect(20.0);
    EXPECT_FALSE(decorator.getOperationalStatus()) << "Should not be operational beyond effect radius";
}

TEST_F(UtilityDecoratorTest, UpgradeFailsWithInsufficientBudget) {
    player->setBudget(50.0);  // Set budget lower than upgrade cost
    UtilityDecorator decorator(std::make_unique<MockUtility>(*baseUtility), player.get());
    
    double initialBudget = player->getBudget();
    auto initialState = std::make_tuple(
        decorator.getLevel(),
        decorator.getCapacity(),
        decorator.getEffectRadius(),
        decorator.getResourceConsumption()
    );
    
    decorator.upgrade();
    
    EXPECT_EQ(player->getBudget(), initialBudget)
        << "Budget should remain unchanged on failed upgrade";
    EXPECT_EQ(std::make_tuple(
        decorator.getLevel(),
        decorator.getCapacity(),
        decorator.getEffectRadius(),
        decorator.getResourceConsumption()
    ), initialState) << "Attributes should remain unchanged on failed upgrade";
}

TEST_F(UtilityDecoratorTest, RepairFailsWithInsufficientBudget) {
    baseUtility->deactivate();  // Start with non-operational utility
    player->setBudget(10.0);    // Set budget lower than repair cost
    UtilityDecorator decorator(std::make_unique<MockUtility>(*baseUtility), player.get());
    
    double initialBudget = player->getBudget();
    
    decorator.repair();
    
    EXPECT_FALSE(decorator.getOperationalStatus())
        << "Utility should remain non-operational when repair fails";
    EXPECT_EQ(player->getBudget(), initialBudget)
        << "Budget should remain unchanged when repair fails";
}

TEST_F(UtilityDecoratorTest, RepairOnOperationalUtilityDoesNothing) {
    UtilityDecorator decorator(std::make_unique<MockUtility>(*baseUtility), player.get());
    
    double initialBudget = player->getBudget();
    
    decorator.repair();
    
    EXPECT_TRUE(decorator.getOperationalStatus())
        << "Utility should remain operational";
    EXPECT_EQ(player->getBudget(), initialBudget)
        << "Budget should not be affected when repairing operational utility";
}