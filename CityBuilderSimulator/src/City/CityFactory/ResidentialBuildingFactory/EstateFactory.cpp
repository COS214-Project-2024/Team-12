#include "EstateFactory.h"
#include "CityComponent/Residential/Estate.h"

std::unique_ptr<ResidentialBuilding> EstateFactory::createBuilding() {
    return std::make_unique<Estate>();
}