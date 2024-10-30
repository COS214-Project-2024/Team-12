#ifndef FLATFACTORY_H
#define FLATFACTORY_H

#include "ResidentialBuildingFactory.h"

class FLatFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding();
};
#endif