#include "House.h"

House::House():ResidentialBuilding(3, 100.0, nullptr, nullptr, nullptr, nullptr) {}

House::House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(3, 100.0, water, power, waste, sewage) {}