#ifndef PARKFACTORY_H
#define PARKFACTORY_H

#include "LandMarkFactory.h"
#include "CityComponent/LandMark/LandMark.h"

class ParkFactory : public LandMark {
public:
    std::unique_ptr<LandMark> createLandMark();
};

#endif