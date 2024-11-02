#include "Townhouse.h"

Townhouse::Townhouse() : ResidentialBuilding(4, 200.00, nullptr, nullptr, nullptr, nullptr) {}

Townhouse::Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(4, 200.00, water, power, waste, sewage) {}