#include "UtitltyFactory.h"

std::shared_ptr<UtilityFlyweight> UtilityFactory::getUtility(const std::string& type) {
    // Check if flyweight exists
    if (flyweights.find(type) == flyweights.end()) {
        // Create a new flyweight if it does not exist
        if (type == "PowerPlant") {
            flyweights[type] = std::make_shared<PowerPlant>();
        } else if (type == "WaterSupply") {
            flyweights[type] = std::make_shared<WaterSupply>();
        } else if (type == "WasteManagement") {
            flyweights[type] = std::make_shared<WasteManagement>();
        } else if (type == "SewageSystem") {
            flyweights[type] = std::make_shared<SewageSystem>();
        }
    }
    // Return existing or newly created flyweight
    return flyweights[type];
}