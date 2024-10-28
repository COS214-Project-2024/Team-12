#include "SawMillFactory.h"
#include "CityComponent/Industrial/SawMill.h"

std::unique_ptr<Industrial> SawMillFactory::createIndustry() {
    return std::make_unique<SawMill>();
}