#include "OilFactory.h"
#include "CityComponent/Resources/Oil.h"

std::unique_ptr<Resource> OilFactory::createResource() {
    return std::make_unique<Oil>();
}