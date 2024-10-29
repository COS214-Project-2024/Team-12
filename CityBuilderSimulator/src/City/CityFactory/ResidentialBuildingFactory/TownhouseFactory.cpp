#include "TownhouseFactory.h"
#include "CityComponent/Residential/Townhouse.h"

std::unique_ptr<ResidentialBuilding> TownhouseFactory::createBuilding() {
    return std::make_unique<Townhouse>();
}