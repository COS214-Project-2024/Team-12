#include "AirportsFactory.h"
#include "CityComponent/Transport/Airports.h"

std::unique_ptr<Transport> AirportsFactory::createTransport() {
    return std::make_unique<Airports>();
}