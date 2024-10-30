#include "MallsFactory.h"
#include "Malls.h"

std::unique_ptr<CommercialBuilding> MallsFactory::createBuilding() {
    return std::make_unique<Malls>();
}