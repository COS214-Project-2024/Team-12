#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include <memory>
#include "CityComponent/LandMark/LandMark.h"

class LandMarkFactory {
public:
    virtual std::unique_ptr<LandMark> createLandMark() = 0;
    virtual ~LandMarkFactory() {}
};

#endif