#include <iostream>
#include <memory>
#include "../src/City/CityComponent/CityComposite/CityComposite.h"
#include "../src/City/CityComponent/CityComponent.h"
#include "../src/City/CityComponent/Residential/ResidentialBuilding.h"  // Example Residential Building
#include "../src/City/CityComponent/Utility/UtilityFlyweight.h"  // Example Utilities
#include "../CityComponent/Resources/IncomeResourceProduct.h"  // Example Income Resources
#include "../CityComponent/Resources/ConstructionResourceProduct.h"  // Example Construction Resources
#include "../NPCs/WorkerNPC/NPCContext.h"  // Worker NPCs
#include "../src/City/CityComponent/Utility/PowerPlant.h"  // Worker NPCs

int main() {
    // Step 1: Create a UtilityFlyweight instance
    std::map<std::string, int> requiredResources = {
        {"Concrete", 50},
        {"Steel", 30},
        {"Glass", 10}
    };

    PowerPlant powerPlant("Power Plant", 10000, 100, 5.0, false, 1, 20, requiredResources);

    // Step 2: Display initial status
    std::cout << "Initial Status of Power Plant:\n";
    powerPlant.displayStatus();

    // Step 3: Activiate the utility and and check its operational status
    std::cout << "\nActivating Power Plant...\n";
    powerPlant.activate();
    std::cout << "Is Power Plant operational? " << (powerPlant.getOperationalStatus() ? "Yes" : "No") << "\n";
    powerPlant.displayStatus();

    // Step 4: Test deactivating the utility
    std::cout << "\nDeactivating Power Plant...\n";
    powerPlant.deactivate();
    std::cout << "Is Power Plant operational? " << (powerPlant.getOperationalStatus() ? "Yes" : "No" ) << "\n";
    powerPlant.displayStatus();

    // Step 5: Test getters
    std::cout << "\nTesting Getters:\n";
    std::cout << "Utility Name: " << powerPlant.getName() << "\n";
    std::cout << "Cost: $" << powerPlant.getCost() << "\n";
    std::cout << "Capacity: " << powerPlant.getCapacity() << " buildings\n";
    std::cout << "Effect Radius: " << powerPlant.getEffectRadius() << " units\n";
    std::cout << "Level: " << powerPlant.getLevel() << "\n";
    std::cout << "Resource Consumption per Cycle: " << powerPlant.getResourceConsumption() << "\n";

    // Step 6: Display resource needs for construction
    std::cout << "\nResource Needs for Construction:\n";
    for (const auto& resource : powerPlant.getResourceNeeds()) {
        std::cout << resource.first << ": " << resource.second << "\n";
    }

    return 0;
}
