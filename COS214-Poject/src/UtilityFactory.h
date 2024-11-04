#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "UtilityFlyweight.h"
#include "PowerPlant.h"
#include "SewageSystem.h"
#include "WasteManagement.h"
#include "WaterSupply.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>

/**
 * @brief Factory class for creating and managing utility flyweight instances.
 */
class UtilityFactory {
private:
    std::unordered_map<std::string, std::shared_ptr<UtilityFlyweight>> flyweights; ///< Stores utility flyweight instances by name.

public:
    /**
     * @brief Retrieves a utility flyweight instance by its string name.
     * 
     * This method returns a shared pointer to the requested utility.
     * If the utility doesn't exist, it is created and added to the map.
     * 
     * @param type The name of the utility (e.g., "PowerPlant", "WaterSupply").
     * @return A shared pointer to the requested UtilityFlyweight instance.
     * @throws std::invalid_argument if the utility type is invalid.
     */
    std::shared_ptr<UtilityFlyweight> getUtility(const std::string& type);

    /**
     * @brief Retrieves a utility flyweight instance by its numeric type.
     * 
     * This method is useful for menu selection, allowing retrieval by integer type.
     * 
     * @param type The integer representing the utility type.
     * @return A shared pointer to the requested UtilityFlyweight instance.
     * @throws std::out_of_range if the type number is not recognized.
     */
    std::shared_ptr<UtilityFlyweight> getUtilityByType(int type);

    /**
     * @brief Gets the name of the utility based on its numeric type.
     * 
     * @param type The integer representing the utility type.
     * @return A string containing the name of the utility.
     */
    static std::string getUtilityName(int type);

    /**
     * @brief Gets the cost of the utility based on its numeric type.
     * 
     * @param type The integer representing the utility type.
     * @return The cost of the utility as a double.
     */
    static double getUtilityCost(int type);
};

#endif
