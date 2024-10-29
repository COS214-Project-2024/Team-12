#include "../src/City/CityComponent/Utility/UtilityFactory.h"


std::shared_ptr<UtilityFlyweight> UtilityFactory::getUtility(const std::string& type) {
    // Return the existing flyweight if it exists
    if(flyweights.find(type) != flyweights.end()) {
        return flyweights[type];
    }

    // Check if flyweight exists
    if (type == "PowerPlant") {
        // Create a new flyweight if it does not exist
        flyweights[type] = std::make_shared<PowerPlant>(
        "PowerPlant", 10000.0, 100, 20.0, true, 1, 50,std::map<std::string, int>{{"Steel", 150}, {"Copper", 50}, {"Fuel", 100}});
    } else if (type == "WaterSupply") {
        flyweights[type] = std::make_shared<WaterSupply>(
        "WaterSupply", 5000.0, 80, 15.0, true, 1, 30, std::map<std::string, int>{{"Steel", 100}, {"Concrete", 200}});
    } else if (type == "WasteManagement") {
        flyweights[type] = std::make_shared<WasteManagement>(
        "WasteManagement", 7000.0, 90, 18.0, true, 1, 40, std::map<std::string, int>{{"Brick", 100}, {"Steel", 80}});
    } else if (type == "SewageSystem") {
        flyweights[type] = std::make_shared<SewageSystem>(
        "SewageSystem", 6000.0, 85, 17.0, true, 1, 35, std::map<std::string, int>{{"Concrete", 150}, {"Steel", 70}});
    } else {
        throw std::out_of_range("Invalid utility type");
    }


    // Return existing or newly created flyweight
    return flyweights[type];
    }

