#include "Office.h"

/**
 * @brief Default constructor for Office.
 * 
 * Initializes an Office building with a base capacity of 600.0 and no connected utilities.
 */
Office::Office() 
    : CommercialBuilding(600.0, nullptr, nullptr, nullptr, nullptr) {}

/**
 * @brief Constructs an Office with specified utility connections.
 * 
 * Initializes an Office building with a base capacity of 600.0 and connects to 
 * the specified water, power, waste, and sewage utilities.
 * 
 * @param water Shared pointer to the water utility.
 * @param power Shared pointer to the power utility.
 * @param waste Shared pointer to the waste utility.
 * @param sewage Shared pointer to the sewage utility.
 */
Office::Office(std::shared_ptr<UtilityFlyweight> water,
               std::shared_ptr<UtilityFlyweight> power,
               std::shared_ptr<UtilityFlyweight> waste,
               std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(600.0, water, power, waste, sewage) {}
