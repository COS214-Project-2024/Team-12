#include "CulturalCenterFactory.h"
#include "CulturalCenter.h"

std::unique_ptr<LandMark> CulturalCenterFactory::createLandMark() {
    return std::make_unique<CulturalCenter>();
}