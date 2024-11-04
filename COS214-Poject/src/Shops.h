#ifndef SHOPS_H
#define SHOPS_H

#include <string>
#include "CommercialBuilding.h"
using namespace std;

/**
 * @brief Represents a commercial building of type Shops.
 * 
 * The Shops class inherits from CommercialBuilding and represents a specific type of commercial building.
 * It includes methods for retrieving building details and display symbols.
 */
class Shops : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Shops.
     * 
     * Initializes a Shops instance with default utilities (no utility connections).
     */
    Shops();

    /**
     * @brief Constructs a Shops instance with utility connections.
     * 
     * @param water Shared pointer to a water utility.
     * @param power Shared pointer to a power utility.
     * @param waste Shared pointer to a waste utility.
     * @param sewage Shared pointer to a sewage utility.
     */
    Shops(std::shared_ptr<UtilityFlyweight> water,
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste,
          std::shared_ptr<UtilityFlyweight> sewage);
    
    /**
     * @brief Gets the display symbol for Shops.
     * 
     * @return char The display symbol representing Shops.
     */
    char getDisplaySymbol() const override { return 'S'; }

    /**
     * @brief Retrieves the building type as a string.
     * 
     * @return std::string The building type, "Shops".
     */
    std::string getBuildingType() const override { return "Shops"; }
};

#endif
