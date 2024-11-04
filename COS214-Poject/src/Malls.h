#ifndef MALLS_H
#define MALLS_H

#include <string>
#include "CommercialBuilding.h"
using namespace std;

/**
 * @brief Represents a Mall, a type of CommercialBuilding.
 * 
 * Malls are initialized with a base area and optional utility connections
 * for water, power, waste management, and sewage.
 */
class Malls : public CommercialBuilding {
public:
    /**
     * @brief Default constructor for Malls.
     * 
     * Initializes a Mall with a base area and no utility connections.
     */
    Malls();

    /**
     * @brief Constructs a Mall with specified utility connections.
     * 
     * @param water Shared pointer to water utility.
     * @param power Shared pointer to power utility.
     * @param waste Shared pointer to waste management utility.
     * @param sewage Shared pointer to sewage management utility.
     */
    Malls(std::shared_ptr<UtilityFlyweight> water,
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste,
          std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Retrieves the display symbol for a Mall.
     * 
     * @return The character 'M' representing the Mall on a map.
     */
    char getDisplaySymbol() const override { return 'M'; }

    /**
     * @brief Retrieves the building type of the Mall.
     * 
     * @return A string "Mall" representing the type of the building.
     */
    std::string getBuildingType() const override { return "Mall"; }
};

#endif
