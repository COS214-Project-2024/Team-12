#ifndef ESTATEFACTORY_H
#define ESTATEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "../Residential/ResidentialBuilding.h"

class EstateFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif