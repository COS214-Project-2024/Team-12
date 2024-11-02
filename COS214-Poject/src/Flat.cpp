#include "Flat.h"

Flat::Flat():ResidentialBuilding(2, 150.00, nullptr, nullptr, nullptr, nullptr) {}

Flat::Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(2, 150.00, water, power, waste, sewage) {}