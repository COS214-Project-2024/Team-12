#include "Shops.h"

/**
 * @brief Default constructor for Shops.
 * 
 * Initializes a Shops instance with a default cost and no utility connections.
 */
Shops::Shops() 
    : CommercialBuilding(200.0, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Constructs a Shops instance with specified utility connections.
 * 
 * This constructor initializes a Shops instance with a specified cost and connections
 * to various utilities (water, power, waste, and sewage).
 * 
 * @param water Shared pointer to a water utility.
 * @param power Shared pointer to a power utility.
 * @param waste Shared pointer to a waste utility.
 * @param sewage Shared pointer to a sewage utility.
 */
Shops::Shops(std::shared_ptr<UtilityFlyweight> water,
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste,
             std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(200.0, water, power, waste, sewage) {}
