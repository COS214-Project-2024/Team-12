#include "CityComponent.h"
#include "CityComposite.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "Industry.h"
#include "House.h"
#include "Flat.h"
#include "Townhouse.h"
#include "Estate.h"
#include "UtilityFlyweight.h"
#include "UtilityFactory.h"
#include "WaterSupply.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "UtilityDecorator.h"
#include "AdvancedTechnologyDecorator.h"
#include "GreenTechnologyDecorator.h"
#include "MapGrid.h"
#include <iostream>
#include <memory>
#include <cmath>
#include <cassert>

// Test Factory Flyweight Reuse
void testFactoryFlyweight() {
    UtilityFactory factory;

    // Create two instances of the same utility type
    auto waterSupply1 = factory.getUtility("WaterSupply");
    auto waterSupply2 = factory.getUtility("WaterSupply");

    // Test that they point to the same object (flyweight should reuse the instance)
    assert(waterSupply1 == waterSupply2 && "Factory should reuse flyweight instance for WaterSupply");

    // Create a different utility type
    auto powerPlant = factory.getUtility("PowerPlant");
    
    // Test that they are different instances
    assert(waterSupply1 != powerPlant && "Factory should create different instances for different types");
}

void testUtilityConnection() {
    MapGrid cityMap(10, 10);  // Assume 10x10 grid for simplicity
    UtilityFactory factory;

    // Create utility and place it on the map
    auto waterSupply = factory.getUtility("WaterSupply");
    int utilityX = 2, utilityY = 3;
    cityMap.placeComponent(waterSupply.get(), utilityX, utilityY);
    
    // Place a building within the effect radius
    ResidentialBuilding *residentialBuilding = new House();
    int buildingX = 3, buildingY = 3; // Adjacent to the water supply
    cityMap.placeComponent(residentialBuilding, buildingX, buildingY);
    
    double distance = std::sqrt(std::pow(utilityX - buildingX, 2) + std::pow(utilityY - buildingY, 2));
    waterSupply->connect(distance);

    // Check if operational and distance criteria are met
    assert(waterSupply->getOperationalStatus() && distance <= waterSupply->getEffectRadius() && "Utility should connect within radius");
}

void testGreenTechnologyDecorator() {
    MapGrid cityMap(10, 10);
    UtilityFactory factory;
    CityComposite city("TestCity", &cityMap);
    
    // Get base utilities
    auto baseWaterSupply1 = factory.getUtility("WaterSupply");
    auto baseWaterSupply2 = factory.getUtility("WaterSupply");
    
    std::cout << "Initial base consumption: " << baseWaterSupply1->getResourceConsumption() << std::endl;
    
    // Create decorators
    auto regularDecorator = std::make_unique<UtilityDecorator>(std::move(baseWaterSupply1), &city);
    auto greenWaterSupply = std::make_unique<GreenTechnologyDecorator>(std::move(baseWaterSupply2), &city);

    city.addBudget(50000);

    std::cout << "\nUpgrading utilities..." << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "\nLevel " << (i+1) << " upgrades:" << std::endl;
        
        regularDecorator->upgrade();
        greenWaterSupply->upgrade();
        
        std::cout << "Regular consumption: " << regularDecorator->getResourceConsumption() << std::endl;
        std::cout << "Green consumption: " << greenWaterSupply->getResourceConsumption() << std::endl;
    }
    
    std::cout << "\nFinal Comparison:" << std::endl;
    std::cout << "Regular utility consumption: " << regularDecorator->getResourceConsumption() << std::endl;
    std::cout << "Green utility consumption: " << greenWaterSupply->getResourceConsumption() << std::endl;
    
    assert(greenWaterSupply->getResourceConsumption() < regularDecorator->getResourceConsumption() && 
           "Green technology should reduce resource consumption compared to regular utility at the same level");
}

void testUtilityRepair() {
    MapGrid cityMap(10, 10);  // Define cityMap locally here
    UtilityFactory factory;
    CityComposite city("TestCity", &cityMap);

    // Create utility and apply decorator for repair cost management
    auto waterSupply = factory.getUtility("WaterSupply");
    auto repairableWaterSupply = std::make_unique<UtilityDecorator>(std::move(waterSupply), &city);

    // Simulate city budget for testing repairs
    city.addBudget(1000);  // Set an initial budget to cover repair costs

    // Deactivate the utility to simulate the need for repair
    repairableWaterSupply->deactivate();

    // Check the utility's operational status before repair
    assert(!repairableWaterSupply->getOperationalStatus() && "Utility should initially be deactivated");

    // Attempt repair and check budget
    double preRepairBudget = city.getBudget();
    repairableWaterSupply->repair();
    
    assert(repairableWaterSupply->getOperationalStatus() && "Utility should be operational after repair");
    assert(city.getBudget() == preRepairBudget - repairableWaterSupply->getUpgradeCost() && "City budget should decrease by repair cost");
}

void testUtilityBoundaryCheck() {
    MapGrid cityMap(10, 10);  // 10x10 grid for simplicity
    UtilityFactory factory;

    // Create utility and place on map
    auto waterSupply = factory.getUtility("WaterSupply");
    int utilityX = 5, utilityY = 5;
    cityMap.placeComponent(waterSupply.get(), utilityX, utilityY);

    // Place building outside the effect radius
    ResidentialBuilding *flat = new Flat();
    int buildingX = 9, buildingY = 9;  // Distance > effectRadius of water supply
    cityMap.placeComponent(flat, buildingX, buildingY);
    
    double distance = std::sqrt(std::pow(utilityX - buildingX, 2) + std::pow(utilityY - buildingY, 2));
    waterSupply->connect(distance);

    // Check that utility does not connect
    assert(!waterSupply->getOperationalStatus() && distance > waterSupply->getEffectRadius() && "Utility should not connect outside of effect radius");
}

void testMultiUtilityConnectionAndUpgrade() {
    MapGrid cityMap(10, 10);
    UtilityFactory factory;
    CityComposite city("MultiUtilityCity", &cityMap);

    // Get different utilities
    auto waterSupply = factory.getUtility("WaterSupply");
    auto powerPlant = factory.getUtility("PowerPlant");

    // Place utilities on the map
    cityMap.placeComponent(waterSupply.get(), 2, 2);
    cityMap.placeComponent(powerPlant.get(), 4, 4);

    // Place buildings within their ranges
    ResidentialBuilding *estate = new Estate();
    ResidentialBuilding *townhouse = new Townhouse();
    cityMap.placeComponent(estate, 3, 3);    // Within range of both utilities
    cityMap.placeComponent(townhouse, 5, 5);  // Within range of power plant only

    // Connect utilities to buildings
    double distanceToHouse = std::sqrt(std::pow(2 - 3, 2) + std::pow(2 - 3, 2));
    double distanceToFactory = std::sqrt(std::pow(4 - 5, 2) + std::pow(4 - 5, 2));

    waterSupply->connect(distanceToHouse);
    powerPlant->connect(distanceToHouse);
    powerPlant->connect(distanceToFactory);

    // Test connection and operation status
    assert(waterSupply->getOperationalStatus() && "Water supply should connect to house");
    assert(powerPlant->getOperationalStatus() && "Power plant should connect to both house and factory");

    // Test upgrades and independence of utility behavior
    city.addBudget(50000);  // Add enough budget for upgrades
    auto greenPowerPlant = std::make_unique<GreenTechnologyDecorator>(std::move(powerPlant), &city);
    
    greenPowerPlant->upgrade();
    greenPowerPlant->upgrade();
    greenPowerPlant->upgrade();
    greenPowerPlant->upgrade();  // Upgrade to level 4 for green tech

    assert(greenPowerPlant->getResourceConsumption() < factory.getUtility("PowerPlant")->getResourceConsumption() && "Green technology should reduce resource consumption");
}

int main(){
    testFactoryFlyweight();
    testGreenTechnologyDecorator();
    testMultiUtilityConnectionAndUpgrade();
    testUtilityBoundaryCheck();
    testUtilityConnection();
    testUtilityRepair();
    std::cout << "All tests passed successfully.\n";
    return 0;
}