#ifndef CULTURALCENTERFACTORY_H
#define CULTURALCENTERFACTORY_H

#include "LandMarkFactory.h"
#include "CityComponent/LandMark/LandMark.h"

class CulturalCenterFactory : public LandMark {
public:
    std::unique_ptr<LandMark> createLandMark();
};

#endif