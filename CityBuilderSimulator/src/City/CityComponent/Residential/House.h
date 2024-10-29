#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

class House : public ResidentialBuilding {
public:
    House();
    House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    double getTaxRevenue();
    std::unique_ptr<ResidentialBuilding> clone() const;
};

#endif