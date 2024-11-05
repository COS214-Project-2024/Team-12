#include <gtest/gtest.h>
#include "../COS214-Poject/src/MallsFactory.h"
#include "../COS214-Poject/src/Malls.h"
#include "../COS214-Poject/src/ResidentialBuilding.h"
#include "../COS214-Poject/src/Estate.h"
#include "../COS214-Poject/src/PowerPlant.h"
#include "../COS214-Poject/src/WaterSupply.h"
#include <memory>
#include <string>
#include <map>

// Test Factory Method for creating building instances
TEST(InfrastructureComponentTest, FactoryMethodCreation) {
    // Step 1: Create a Mall using MallsFactory
    MallsFactory mallFactory;
    std::unique_ptr<CommercialBuilding> mall = mallFactory.createBuilding();

    // Verify that the mall has the expected type and display symbol
    EXPECT_EQ(mall->getBuildingType(), "Mall");
    EXPECT_EQ(mall->getDisplaySymbol(), 'M');

    // Step 2: Create an Estate using ResidentialBuildingFactory
    auto estate = std::make_unique<Estate>();  // Assuming Estate uses default constructor for simplicity

    // Verify that the estate has the expected type and display symbol
    EXPECT_EQ(estate->getBuildingType(), "Estate");
    EXPECT_EQ(estate->getDisplaySymbol(), 'E');
}

// Test Prototype Pattern for cloning utility instances
TEST(InfrastructureComponentTest, PrototypePatternCloning) {
    // Step 1: Create an original PowerPlant instance
    auto originalPowerPlant = std::make_shared<PowerPlant>("Central Power", 200.0, 100, 4.0, true, 1, 15, std::map<std::string, int>{{"Steel", 60}, {"Copper", 40}, {"Coal", 30}});
    
    // Step 2: Clone the PowerPlant instance
    std::shared_ptr<UtilityFlyweight> clonedPowerPlant = originalPowerPlant->clone();

    // Verify that the cloned instance has the same properties as the original
    EXPECT_EQ(clonedPowerPlant->getName(), originalPowerPlant->getName());
    EXPECT_EQ(clonedPowerPlant->getCost(), originalPowerPlant->getCost());
    EXPECT_EQ(clonedPowerPlant->getCapacity(), originalPowerPlant->getCapacity());
    EXPECT_EQ(clonedPowerPlant->getEffectRadius(), originalPowerPlant->getEffectRadius());
    EXPECT_EQ(clonedPowerPlant->getResourceNeeds(), originalPowerPlant->getResourceNeeds());

    // Step 3: Create an original WaterSupply instance and clone it
    auto originalWaterSupply = std::make_shared<WaterSupply>("City Water Supply", 150.0, 60, 3.0, true, 1, 10, std::map<std::string, int>{{"Steel", 40}, {"Plastic", 20}});
    std::shared_ptr<UtilityFlyweight> clonedWaterSupply = originalWaterSupply->clone();

    // Verify that the cloned WaterSupply has the same properties as the original
    EXPECT_EQ(clonedWaterSupply->getName(), originalWaterSupply->getName());
    EXPECT_EQ(clonedWaterSupply->getCost(), originalWaterSupply->getCost());
    EXPECT_EQ(clonedWaterSupply->getCapacity(), originalWaterSupply->getCapacity());
    EXPECT_EQ(clonedWaterSupply->getEffectRadius(), originalWaterSupply->getEffectRadius());
    EXPECT_EQ(clonedWaterSupply->getResourceNeeds(), originalWaterSupply->getResourceNeeds());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
