#include "ShopsFactory.h"
#include "Shops.h"

std::unique_ptr<CommercialBuilding> ShopsFactory::createBuilding() {
    return std::make_unique<Shops>();
}