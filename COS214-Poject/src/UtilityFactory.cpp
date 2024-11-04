#include "UtilityFactory.h"

/**
 * @brief Retrieves a utility flyweight instance by its string name.
 * 
 * If a flyweight of the specified type already exists, it returns it.
 * If not, it creates a new flyweight, adds it to the map, and returns a clone.
 * 
 * @param type The name of the utility (e.g., "PowerPlant", "WaterSupply").
 * @return A shared pointer to the requested UtilityFlyweight instance.
 * @throws std::out_of_range if the utility type is invalid.
 */
std::shared_ptr<UtilityFlyweight> UtilityFactory::getUtility(const std::string& type) {
    // Return the existing flyweight if it exists
    if(flyweights.find(type) != flyweights.end()) {
        return flyweights[type];
    }

    // Check if flyweight exists
    if (type == "PowerPlant") {
        flyweights[type] = std::make_shared<PowerPlant>();  // Create new PowerPlant flyweight
    } else if (type == "WaterSupply") {
        flyweights[type] = std::make_shared<WaterSupply>();  // Create new WaterSupply flyweight
    } else if (type == "WasteManagement") {
        flyweights[type] = std::make_shared<WasteManagement>();  // Create new WasteManagement flyweight
    } else if (type == "SewageSystem") {
        flyweights[type] = std::make_shared<SewageSystem>();  // Create new SewageSystem flyweight
    } else {
        throw std::out_of_range("Invalid utility type");
    }

    return flyweights[type]->clone(); // Return a clone of the new flyweight
}

/**
 * @brief Retrieves a utility flyweight instance by its numeric type.
 * 
 * Allows retrieval of utilities by numeric type for ease of menu selection.
 * 
 * @param type The integer representing the utility type.
 * @return A shared pointer to the requested UtilityFlyweight instance.
 * @throws std::out_of_range if the utility type number is invalid.
 */
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

/**
 * @brief Gets the name of the utility based on its numeric type.
 * 
 * @param type The integer representing the utility type.
 * @return A string containing the name of the utility.
 */
std::string UtilityFactory::getUtilityName(int type) {
    switch(type) {
        case 1: return "Water Supply";
        case 2: return "Power Plant";
        case 3: return "Sewage System";
        case 4: return "Waste Management";
        default: return "Unknown";
    }
}

/**
 * @brief Gets the cost of the utility based on its numeric type.
 * 
 * @param type The integer representing the utility type.
 * @return The cost of the utility as a double.
 */
double UtilityFactory::getUtilityCost(int type) {
    switch(type) {
        case 1: return 150.0;  // Water Supply
        case 2: return 200.0;  // Power Plant
        case 3: return 175.0;  // Sewage System
        case 4: return 125.0;  // Waste Management
        default: return 0.0;
    }
}
