// #include "gtest/gtest.h"
// #include "../src/GreenTechnologyDecorator.h"
// #include "../src/CityComposite.h"

// class GreenTechnologyDecoratorTest : public ::testing::Test {};

// TEST_F(GreenTechnologyDecoratorTest, UpgradeBeforeGreenTechnologyActivation) {
//     MockCityComposite player("TestCity", 10000.0);  // Sufficient budget for testing
//     auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 1, 30, std::map<std::string, int>{{"Steel", 100}});
//     GreenTechnologyDecorator decorator(std::move(utility), &player);

//     // First upgrade
//     decorator.upgrade();
//     EXPECT_EQ(decorator.getLevel(), 2);
//     EXPECT_EQ(decorator.getResourceConsumption(), 35);
//     EXPECT_EQ(player.getBudget(), 10000.0 - decorator.getUpgradeCost());

//     // Second upgrade
//     decorator.upgrade();
//     EXPECT_EQ(decorator.getLevel(), 3);
//     EXPECT_EQ(decorator.getResourceConsumption(), 40);
// }

// TEST_F(GreenTechnologyDecoratorTest, UpgradeActivatesGreenTechnology) {
//     MockCityComposite player("TestCity", 10000.0);
//     auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 3, 40, std::map<std::string, int>{{"Steel", 100}});
//     GreenTechnologyDecorator decorator(std::move(utility), &player);

//     // Upgrade to level 4, should activate green technology
//     decorator.upgrade();
//     EXPECT_EQ(decorator.getLevel(), 4);
//     EXPECT_EQ(decorator.getResourceConsumption(), 35);  // Reduced due to green tech
//     EXPECT_EQ(player.getBudget(), 10000.0 - decorator.getUpgradeCost());
// }

// TEST_F(GreenTechnologyDecoratorTest, ContinuedGreenTechnologyAfterLevel4) {
//     MockCityComposite player("TestCity", 10000.0);
//     auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 4, 35, std::map<std::string, int>{{"Steel", 100}});
//     GreenTechnologyDecorator decorator(std::move(utility), &player);

//     // Further upgrades should retain green tech benefits
//     decorator.upgrade();  // Level 5
//     EXPECT_EQ(decorator.getLevel(), 5);
//     EXPECT_EQ(decorator.getResourceConsumption(), 40);
// }
/* #include "gtest/gtest.h"
#include "../COS214-Poject/src/GreenTechnologyDecorator.h"
#include "../COS214-Poject/src/CityComposite.h"
#include "../COS214-Poject/src/MockCityComposite.h"
#include "../COS214-Poject/src/Utility/MockUtility.h"

class GreenTechnologyDecoratorTest : public ::testing::Test {};

TEST_F(GreenTechnologyDecoratorTest, UpgradeBeforeGreenTechnologyActivation) {
    MockCityComposite player("TestCity", 10000.0);  // Sufficient budget for testing
    auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 1, 30, std::map<std::string, int>{{"Steel", 100}});
    GreenTechnologyDecorator decorator(std::move(utility), &player);

    // First upgrade
    decorator.upgrade();
    EXPECT_EQ(decorator.getLevel(), 2);
    EXPECT_EQ(decorator.getResourceConsumption(), 35);
    EXPECT_EQ(player.getBudget(), 10000.0 - decorator.getUpgradeCost());

    // Second upgrade
    decorator.upgrade();
    EXPECT_EQ(decorator.getLevel(), 3);
    EXPECT_EQ(decorator.getResourceConsumption(), 40);
}

TEST_F(GreenTechnologyDecoratorTest, UpgradeActivatesGreenTechnology) {
    MockCityComposite player("TestCity", 10000.0);
    auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 3, 40, std::map<std::string, int>{{"Steel", 100}});
    GreenTechnologyDecorator decorator(std::move(utility), &player);

    // Upgrade to level 4, should activate green technology
    decorator.upgrade();
    EXPECT_EQ(decorator.getLevel(), 4);
    EXPECT_EQ(decorator.getResourceConsumption(), 35);  // Reduced due to green tech
    EXPECT_EQ(player.getBudget(), 10000.0 - decorator.getUpgradeCost());
}

TEST_F(GreenTechnologyDecoratorTest, ContinuedGreenTechnologyAfterLevel4) {
    MockCityComposite player("TestCity", 10000.0);
    auto utility = std::make_unique<MockUtility>("TestUtility", 1000.0, 100, 20.0, true, 4, 35, std::map<std::string, int>{{"Steel", 100}});
    GreenTechnologyDecorator decorator(std::move(utility), &player);

    // Further upgrades should retain green tech benefits
    decorator.upgrade();  // Level 5
    EXPECT_EQ(decorator.getLevel(), 5);
    EXPECT_EQ(decorator.getResourceConsumption(), 40);
}
 */