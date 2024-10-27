#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

class Estate : public ResidentialBuilding {
public:
    Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    double getTaxRevenue();
    std::unique_ptr<ResidentialBuilding> clone() const;
};

#endif