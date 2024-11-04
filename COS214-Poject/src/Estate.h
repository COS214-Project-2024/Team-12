#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

#include "taxCollector.h"
#include "CityComposite.h"


class Estate : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 300;
    
    Estate();
    Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
           std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    char getDisplaySymbol() const override { return 'E'; }
    std::string getBuildingType() const override { return "Estate"; }

};

#endif