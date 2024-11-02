#ifndef OFFICE_H
#define OFFICE_H

#include <string>

#include "CommercialBuilding.h"
using namespace std;


class Office: public CommercialBuilding{
    Office();
    Office(std::shared_ptr<UtilityFlyweight> water,
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste,
          std::shared_ptr<UtilityFlyweight> sewage);
    
    char getDisplaySymbol() const  { return 'O'; }
    std::string getBuildingType() override { return "Office"; }
};


#endif