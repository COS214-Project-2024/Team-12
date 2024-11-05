#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

/**
 * @class Townhouse
 * @brief A concrete class representing a townhouse, derived from ResidentialBuilding.
 * 
 * The Townhouse class defines a residential building type with specific characteristics.
 * It provides utility connections (e.g., water, power, waste, sewage) and has a display symbol.
 */
class Townhouse : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 200; /**< Base cost for constructing a townhouse. */
    
    /**
     * @brief Default constructor for Townhouse.
     */
    Townhouse();

    /**
     * @brief Constructs a Townhouse with specified utility connections.
     * 
     * @param water A shared pointer to the water utility connection.
     * @param power A shared pointer to the power utility connection.
     * @param waste A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage system utility.
     */
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
              std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    
    /**
     * @brief Returns the display symbol for the townhouse.
     * 
     * @return char The symbol representing a townhouse ('T').
     */
    char getDisplaySymbol() const override { return 'T'; }

    /**
     * @brief Returns the building type as a string.
     * 
     * @return std::string The type of the building ("Townhouse").
     */
    std::string getBuildingType() const override { return "Townhouse"; }

};

#endif
