/**
 * @file House.h
 * @brief Header file for the House class, representing a residential building.
 */

#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

/**
 * @class House
 * @brief Represents a house, which is a type of residential building.
 * 
 * This class inherits from the ResidentialBuilding class and adds specific
 * properties and methods related to a house.
 */
class House : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 100; ///< Base cost of the house

    /**
     * @brief Default constructor for the House class.
     * 
     * Initializes a house with default values for its utilities.
     */
    House();

    /**
     * @brief Parameterized constructor for the House class.
     * 
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste utility.
     * @param sewage A shared pointer to the sewage utility.
     */
    House(std::shared_ptr<UtilityFlyweight> water, 
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste, 
          std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Gets the display symbol for the house.
     * 
     * @return A character representing the house (H).
     */
    char getDisplaySymbol() const override { return 'H'; }

    /**
     * @brief Gets the building type of the house.
     * 
     * @return A string representing the type of building.
     */
    std::string getBuildingType() const override { return "House"; }
};

#endif
