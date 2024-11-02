#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include <memory>
#include "ResidentialBuilding.h"

class ResidentialBuildingFactory {
public:
    virtual std::unique_ptr<ResidentialBuilding> createBuilding() = 0;
    virtual ~ResidentialBuildingFactory() {}
};

#endif