#include "Malls.h"


Malls::Malls() 
    : CommercialBuilding(600.0, nullptr, nullptr, nullptr, nullptr) {}

Malls::Malls(std::shared_ptr<UtilityFlyweight> water,
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste,
             std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(600.0, water, power, waste, sewage) {}