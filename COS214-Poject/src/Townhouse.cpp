#include "Townhouse.h"

/**
 * @brief Default constructor for Townhouse.
 * 
 * Constructs a Townhouse with a default capacity of 4 occupants and a cost of 200.00,
 * with no initial utility connections.
 */
Townhouse::Townhouse() : ResidentialBuilding(4, 200.00, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Parameterized constructor for Townhouse.
 * 
 * Constructs a Townhouse with specified utility connections and assigns it a capacity of
 * 4 occupants and a cost of 200.00.
 * 
 * @param water A shared pointer to the water utility connection.
 * @param power A shared pointer to the power utility connection.
 * @param waste A shared pointer to the waste management utility.
 * @param sewage A shared pointer to the sewage system utility.
 */
Townhouse::Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                     std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(4, 200.00, water, power, waste, sewage) {}
