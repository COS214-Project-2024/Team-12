#include "UtilityFactory.h"

std::shared_ptr<UtilityFlyweight> UtilityFactory::getUtility(const std::string& type) {
    // Return the existing flyweight if it exists
    if(flyweights.find(type) != flyweights.end()) {
        return flyweights[type];
    }

    // Check if flyweight exists
    if (type == "PowerPlant") {
        // Create a new flyweight if it does not exist
        flyweights[type] = std::make_shared<PowerPlant>();
    } else if (type == "WaterSupply") {
        flyweights[type] = std::make_shared<WaterSupply>();
    } else if (type == "WasteManagement") {
        flyweights[type] = std::make_shared<WasteManagement>();
    } else if (type == "SewageSystem") {
        flyweights[type] = std::make_shared<SewageSystem>();
    } else {
        throw std::out_of_range("Invalid utility type");
    }


    return flyweights[type]->clone(); // Return a clone of the new flyweight
}

std::shared_ptr<UtilityFlyweight> UtilityFactory::getUtilityByType(int type) {
    switch(type) {
        case 1: return getUtility("WaterSupply");
        case 2: return getUtility("PowerPlant");
        case 3: return getUtility("SewageSystem");
        case 4: return getUtility("WasteManagement");
        default:
            throw std::out_of_range("Invalid utility type number");
    }
}

std::string UtilityFactory::getUtilityName(int type) {
    switch(type) {
        case 1: return "Water Supply";
        case 2: return "Power Plant";
        case 3: return "Sewage System";
        case 4: return "Waste Management";
        default: return "Unknown";
    }
}

double UtilityFactory::getUtilityCost(int type) {
    switch(type) {
        case 1: return 150.0;  // Water Supply
        case 2: return 200.0;  // Power Plant
        case 3: return 175.0;  // Sewage System
        case 4: return 125.0;  // Waste Management
        default: return 0.0;
    }
}