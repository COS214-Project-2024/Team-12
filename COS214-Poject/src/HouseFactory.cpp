#include "HouseFactory.h"
#include "House.h"

std::unique_ptr<ResidentialBuilding> HouseFactory::createBuilding(){
    return std::make_unique<House>();
}

