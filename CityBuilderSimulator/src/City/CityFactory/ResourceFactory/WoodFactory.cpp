#include "WoodFactory.h"
#include "CityComponent/Resources/Wood.h"

std::unique_ptr<Resource> WoodFactory::createResource() {
    return std::make_unique<Wood>();
}