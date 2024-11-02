#include "Shops.h"


Shops::Shops() 
    : CommercialBuilding(400.0, nullptr, nullptr, nullptr, nullptr) {}

Shops::Shops(std::shared_ptr<UtilityFlyweight> water,
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste,
             std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(400.0, water, power, waste, sewage) {}

