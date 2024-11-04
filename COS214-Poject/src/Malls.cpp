#include "Malls.h"

/**
 * @brief Default constructor for Malls.
 * 
 * Initializes a Mall with a base area of 400.0 and no utility connections.
 */
Malls::Malls() 
    : CommercialBuilding(400.0, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Constructs a Mall with specified utility connections.
 * 
 * @param water Shared pointer to water utility.
 * @param power Shared pointer to power utility.
 * @param waste Shared pointer to waste management utility.
 * @param sewage Shared pointer to sewage management utility.
 */
Malls::Malls(std::shared_ptr<UtilityFlyweight> water,
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste,
             std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(400.0, water, power, waste, sewage) {}
