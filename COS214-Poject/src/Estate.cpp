#include "Estate.h"

/**
 * @brief Default constructor for the Estate class.
 * 
 * Initializes an estate with a base capacity of 6 and a base cost of $300. 
 * All utility connections are set to nullptr.
 */
Estate::Estate() : ResidentialBuilding(6, 300.00, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Parameterized constructor for the Estate class.
 * 
 * Initializes an estate with specified utility connections and a base capacity 
 * of 6 and a base cost of $300.
 * 
 * @param water A shared pointer to the water utility.
 * @param power A shared pointer to the power utility.
 * @param waste A shared pointer to the waste management utility.
 * @param sewage A shared pointer to the sewage management utility.
 */
Estate::Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(6, 300.00, water, power, waste, sewage) {}
