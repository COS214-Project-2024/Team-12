#ifndef GREENTECHNOLOGYDECORATOR_H
#define GREENTECHNOLOGYDECORATOR_H

#include "UtilityDecorator.h"

class GreenTechnologyDecorator : public UtilityDecorator {
public:
    GreenTechnologyDecorator(std::unique_ptr<UtilityFlyweight> utility, CityComposite* player);
    void upgrade();
};

#endif