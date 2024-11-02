#ifndef PARKFACTORY_H
#define PARKFACTORY_H

#include "LandMarkFactory.h"
#include "LandMark.h"

class ParkFactory : public LandMark {
public:
    std::unique_ptr<LandMark> createLandMark();
};

#endif