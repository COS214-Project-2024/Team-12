#include "RoadsFactory.h"
#include "CityComponent/Transport/Roads.h"

std::unique_ptr<Transport> RoadsFactory::createTransport() {
    return std::make_unique<Roads>();
}