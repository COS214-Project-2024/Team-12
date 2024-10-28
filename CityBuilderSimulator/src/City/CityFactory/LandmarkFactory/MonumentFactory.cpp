#include "MonumentFactory.h"
#include "CityComponent/LandMark/Monument.h"

std::unique_ptr<LandMark> MonumentFactory::createLandMark() {
    return std::make_unique<Monument>();
}