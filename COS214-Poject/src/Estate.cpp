#include "Estate.h"

Estate::Estate() : ResidentialBuilding(6, 300.00, nullptr, nullptr, nullptr, nullptr) {}

Estate::Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(6, 300.00, water, power, waste, sewage) {}