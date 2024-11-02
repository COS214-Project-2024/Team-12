#include "FlatFactory.h"
#include "Flat.h"

std::unique_ptr<ResidentialBuilding> FLatFactory::createBuilding() {
    return std::make_unique<Flat>();
}