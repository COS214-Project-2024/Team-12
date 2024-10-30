#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "ResidentialBuilding.h"

class HouseFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif