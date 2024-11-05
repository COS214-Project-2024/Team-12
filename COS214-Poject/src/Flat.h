#ifndef FLAT_H
#define FLAT_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

/**
 * @brief Represents a residential building of type Flat.
 * 
 * The Flat class inherits from ResidentialBuilding and includes 
 * specific properties and methods related to a flat residential 
 * structure, such as base cost and utility connections.
 */
class Flat : public ResidentialBuilding {
public:
    /// Base cost of constructing a Flat.
    static constexpr int BASE_COST = 150;
    
    /**
     * @brief Default constructor for Flat.
     */
    Flat();
    
    /**
     * @brief Parameterized constructor for Flat.
     * 
     * @param water A shared pointer to the UtilityFlyweight for water supply.
     * @param power A shared pointer to the UtilityFlyweight for power supply.
     * @param waste A shared pointer to the UtilityFlyweight for waste management.
     * @param sewage A shared pointer to the UtilityFlyweight for sewage management.
     */
    Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
         std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Get the display symbol for Flat.
     * 
     * @return A character symbol representing the Flat (usually 'F').
     */
    char getDisplaySymbol() const override { return 'F'; }

    /**
     * @brief Get the building type for Flat.
     * 
     * @return A string representing the type of building, which is "Flat".
     */
    std::string getBuildingType() const override { return "Flat"; }

};

#endif
