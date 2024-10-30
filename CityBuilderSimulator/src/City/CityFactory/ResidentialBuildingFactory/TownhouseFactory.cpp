#include "TownhouseFactory.h"
#include "../Residential/Townhouse.h"

std::unique_ptr<ResidentialBuilding> TownhouseFactory::createBuilding() {
    return std::make_unique<Townhouse>();
}