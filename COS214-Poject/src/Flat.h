#ifndef FLAT_H
#define FLAT_H

#include "ResidentialBuilding.h"

#include "taxCollector.h"
#include "CityComposite.h"


class Flat : public ResidentialBuilding {
public:
    static constexpr int BASE_COST = 150;
    
    Flat();
    Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);

    char getDisplaySymbol() const override { return 'F'; }
    std::string getBuildingType() const override { return "Flat"; }

};

#endif