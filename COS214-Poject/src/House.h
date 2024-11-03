#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

#include "taxCollector.h"
#include "CityComposite.h"



class House : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 100;
    
    House();
    House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    
    std::string getDisplaySymbol() const override { return "⌂"; }
    std::string getBuildingType() override { return "House"; }
};

#endif