#include "Office.h"

Office::Office() 
    : CommercialBuilding(600.0, nullptr, nullptr, nullptr, nullptr) {}

Office::Office(std::shared_ptr<UtilityFlyweight> water,
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste,
             std::shared_ptr<UtilityFlyweight> sewage)
    : CommercialBuilding(600.0, water, power, waste, sewage) {}