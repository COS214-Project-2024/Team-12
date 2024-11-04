#include "CulturalCenterFactory.h"
#include "CulturalCenter.h"

std::unique_ptr<LandMark> CulturalCenterFactory::createLandMark() {
    return std::make_unique<CulturalCenter>("DefaultType", 0, 0.0, nullptr, nullptr, nullptr, nullptr);
}