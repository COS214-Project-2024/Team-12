#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "CityComponent/Residential/ResidentialBuilding.h"

class HouseFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif