#ifndef OFFICEFACTORY_H
#define OFFICEFACTORY_H

#include "CommercialFactory.h"
#include "CommercialBuilding.h"

class OfficeFactory : public CommercialFactory {
public:
    std::unique_ptr<CommercialBuilding> createBuilding();
};

#endif