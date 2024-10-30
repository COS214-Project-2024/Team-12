#include "ParkFactory.h"
#include "Park.h"

std::unique_ptr<LandMark> ParkFactory::createLandMark() {
    return std::make_unique<Park>();
}