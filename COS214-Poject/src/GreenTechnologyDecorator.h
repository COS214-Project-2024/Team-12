#ifndef GREENTECHNOLOGYDECORATOR_H
#define GREENTECHNOLOGYDECORATOR_H

#include "UtilityDecorator.h"

class GreenTechnologyDecorator : public UtilityDecorator {
public:
    GreenTechnologyDecorator(std::shared_ptr<UtilityFlyweight> utility, CityComposite* player);
    void upgrade();
    int getResourceConsumption() const ;
    double getUpgradeCost() const;
};

#endif