#ifndef MALLSFACTORY_H
#define MALLSFACTORY_H

#include "CommercialFactory.h"
#include "CityComponent/Commercial/CommercialBuilding.h"

class MallsFactory : public CommercialFactory {
public:
    std::unique_ptr<CommercialBuilding> createBuilding();
};

#endif