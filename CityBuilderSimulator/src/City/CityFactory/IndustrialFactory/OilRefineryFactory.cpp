#include "OilRefineryFactory.h"
#include "CityComponent/Industrial/OilRefinery.h"

std::unique_ptr<Industrial> OilRefineryFactory::createIndustry() {
    return std::make_unique<OilRefinery>();
}