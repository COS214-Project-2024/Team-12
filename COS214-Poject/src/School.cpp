#include "School.h"
#include <iostream>

School::School(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power, 
               std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage, 
               const std::string& buildingStatus)
    : PublicService(water, power, waste, sewage), status(buildingStatus) {
}

// Implement the provideService method
void School::provideService() {
    if (hasUtilities()) {
        status = "Operational";
        std::cout << "School is operational and providing educational services to the community.\n";
    } else {
        status = "Non-operational";
        std::cout << "School is not operational due to insufficient utilities.\n";
        if (!waterSupply) std::cout << " - Water service is missing.\n";
        if (!powerSupply) std::cout << " - Power supply is missing.\n";
        if (!wasteManagement) std::cout << " - Waste management service is missing.\n";
        if (!sewageManagement) std::cout << " - Sewage service is missing.\n";
    }
}

// Implement the displayStatus method
void School::displayStatus() {
    std::cout << "School Status: " << status << std::endl;
    std::cout << "Utility Coverage: " << getUtilityCoverage() << "/4 utilities connected.\n";
}

// Implement the getDisplaySymbol method for map display
char School::getDisplaySymbol() const {
    return 'S';  // Using 'S' to represent School on the map
}
