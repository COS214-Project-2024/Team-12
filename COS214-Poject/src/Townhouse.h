#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"

#include "taxCollector.h"
#include "CityComposite.h"


class Townhouse : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 200;
    
    Townhouse();
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
              std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    
    std::string getDisplaySymbol() const override { return "T"; }
    std::string getBuildingType() override { return "Townhouse"; }
};

#endif