#include "ParkFactory.h"
#include "CityComponent/LandMark/Park.h"

std::unique_ptr<LandMark> ParkFactory::createLandMark() {
    return std::make_unique<Park>();
}