#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

/**
 * @class House
 * @brief Represents a house in the city simulation, a type of ResidentialBuilding.
 *
 * The House class is a specific type of ResidentialBuilding, with a unique display symbol
 * and a static base cost. It connects to various utility flyweights, such as water, power,
 * waste, and sewage, which enhance functionality in the simulation.
 */
class House : public ResidentialBuilding {
public:
    /** 
     * @brief The base cost to construct a House.
     * 
     * A constant integer value representing the default cost required to build a house.
     */
    static constexpr int BASE_COST = 100;

    /**
     * @brief Default constructor for a House object.
     *
     * Initializes a House without connecting to any specific utilities.
     */
    House();

    /**
     * @brief Constructs a House with specified utility connections.
     * 
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste utility.
     * @param sewage A shared pointer to the sewage utility.
     *
     * Initializes the house with connections to the given utility flyweights.
     */
    House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Returns the display symbol for the House.
     * 
     * @return char A character representing the House in the city map ('H').
     */
    char getDisplaySymbol() const override;

    /**
     * @brief Returns the type of building.
     * 
     * @return std::string The string "House" representing the building type.
     */
    std::string getBuildingType() const override;
};

#endif
