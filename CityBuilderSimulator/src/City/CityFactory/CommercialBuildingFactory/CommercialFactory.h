#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <memory>
#include "../Commercial/CommercialBuilding.h"

class CommercialFactory {
public:
    virtual std::unique_ptr<CommercialBuilding> createBuilding() = 0;
    virtual ~CommercialFactory() {}
};

#endif