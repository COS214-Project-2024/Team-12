#include "MallsFactory.h"
#include "CityComponent/COmmercial/Malls.h"

std::unique_ptr<CommercialBuilding> MallsFactory::createBuilding() {
    return std::make_unique<Malls>();
}