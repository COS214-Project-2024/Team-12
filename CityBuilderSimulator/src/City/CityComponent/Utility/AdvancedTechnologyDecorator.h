#ifndef ADVANCEDTECHNOLOGYDECORATOR_H
#define ADVANCEDTECHNOLOGYDECORATOR_H

#include "UtilityDecorator.h"

class AdvancedTechnologyDecorator : public UtilityDecorator {
public:
    AdvancedTechnologyDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite* player);
    void upgrade();
};

#endif