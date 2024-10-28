#include "MineFactory.h"
#include "CityComponent/Resources/Ore.h"

std::unique_ptr<Resource> MineFactory::createResource() {
    return std::make_unique<Ore>();
}