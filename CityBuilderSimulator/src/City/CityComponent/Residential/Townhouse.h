#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"

class Townhouse : public ResidentialBuilding {
public:
    Townhouse();
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    double getTaxRevenue();
    std::unique_ptr<ResidentialBuilding> clone() const;
};

#endif