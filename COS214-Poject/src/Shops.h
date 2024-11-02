#ifndef SHOPS_H
#define SHOPs_H

#include <string>

#include "CommercialBuilding.h"
using namespace std;


class Shops:public CommercialBuilding{
public:
    Shops();
    Shops(std::shared_ptr<UtilityFlyweight> water,
          std::shared_ptr<UtilityFlyweight> power,
          std::shared_ptr<UtilityFlyweight> waste,
          std::shared_ptr<UtilityFlyweight> sewage);
    
    char getDisplaySymbol() const  { return 'S'; }
    std::string getBuildingType() override { return "Shops"; }
};


#endif