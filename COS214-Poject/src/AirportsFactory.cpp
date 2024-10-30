#include "AirportsFactory.h"
#include "Airports.h"

std::unique_ptr<Transport> AirportsFactory::createTransport() {
    return std::make_unique<Airports>();
}