#ifndef SHOPSFACTORY_H
#define SHOPSFACTORY_H

#include "CommercialFactory.h"
#include "CityComponent/Commercial/CommercialBuilding.h"

class ShopsFactory : public CommercialFactory {
public:
    std::unique_ptr<CommercialBuilding> createBuilding();
};

#endif