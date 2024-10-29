#include "../src/City/CityFactory/TransportationFactory/RoadsFactory.h"
#include "../src/City/CityComponent/Transport/Roads.h"

std::unique_ptr<Transport> RoadsFactory::createTransport() {
    return std::make_unique<Roads>();
}