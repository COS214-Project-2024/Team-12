#include "SmelterFactory.h"
#include "CityComponent/Industrial/Smelter.h"

std::unique_ptr<Industrial> SmelterFactory::createIndustry() {
    return std::make_unique<Smelter>();
}