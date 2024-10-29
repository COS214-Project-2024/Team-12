#include "ShopsFactory.h"
#include "CityComponent/COmmercial/Shops.h"

std::unique_ptr<CommercialBuilding> ShopsFactory::createBuilding() {
    return std::make_unique<Shops>();
}