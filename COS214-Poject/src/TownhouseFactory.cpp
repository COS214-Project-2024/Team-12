#include "TownhouseFactory.h"
#include "Townhouse.h"

std::unique_ptr<ResidentialBuilding> TownhouseFactory::createBuilding() {
    return std::make_unique<Townhouse>();
}