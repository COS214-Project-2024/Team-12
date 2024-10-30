#ifndef MONUMENTFACTORY_H
#define MONUMENTFACTORY_H

#include "LandMarkFactory.h"
#include "../LandMark/LandMark.h"

class MonumentFactory : public LandMark {
public:
    std::unique_ptr<LandMark> createLandMark();
};

#endif