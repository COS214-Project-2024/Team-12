#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "CityComponent/Residential/ResidentialBuilding.h"

class TownhouseFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif