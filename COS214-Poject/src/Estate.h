#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

/**
 * @class Estate
 * @brief Represents an estate building in the city simulation.
 * 
 * Inherits from the ResidentialBuilding class and provides functionality specific 
 * to estate buildings, including their cost and utility connections.
 */
class Estate : public ResidentialBuilding {
public:
    /** Base cost for constructing an estate. */
    static constexpr int BASE_COST = 300;

    /**
     * @brief Default constructor for the Estate class.
     * 
     * Initializes an estate with default settings.
     */
    Estate();

    /**
     * @brief Parameterized constructor for the Estate class.
     * 
     * Initializes an estate with the specified utility connections.
     * 
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage management utility.
     */
    Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
           std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Gets the display symbol for the estate.
     * 
     * @return A character representing the estate on the city grid ('E').
     */
    char getDisplaySymbol() const override { return 'E'; }

    /**
     * @brief Gets the type of the building.
     * 
     * @return A string indicating the building type ("Estate").
     */
    std::string getBuildingType() const override { return "Estate"; }

};

#endif
