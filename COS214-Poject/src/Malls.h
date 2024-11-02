#ifndef MALLS_H
#define MALLS_H

#include <string>

#include "CommercialBuilding.h"
using namespace std;

class Malls: public CommercialBuilding{
public:
    Malls();
    Malls(std::shared_ptr<UtilityFlyweight> water,
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste,
          std::shared_ptr<UtilityFlyweight> sewage);
    
    char getDisplaySymbol() const  { return 'M'; }
    std::string getBuildingType() override { return "Mall"; }
};


#endif