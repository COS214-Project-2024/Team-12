#include "Flat.h"

/**
 * @brief Default constructor for the Flat class.
 * 
 * This constructor initializes a Flat object with default parameters,
 * setting the number of floors to 2 and the base cost to $150.00.
 */
Flat::Flat() : ResidentialBuilding(2, 150.00, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Parameterized constructor for the Flat class.
 * 
 * This constructor initializes a Flat object with the specified utility
 * connections, the number of floors set to 2, and the base cost set to 
 * $150.00.
 * 
 * @param water A shared pointer to the UtilityFlyweight for water supply.
 * @param power A shared pointer to the UtilityFlyweight for power supply.
 * @param waste A shared pointer to the UtilityFlyweight for waste management.
 * @param sewage A shared pointer to the UtilityFlyweight for sewage management.
 */
Flat::Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
           std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
    : ResidentialBuilding(2, 150.00, water, power, waste, sewage) {}
