#include "../City/CityFactory/TransportationFactory/AirportsFactory.h"
#include "../City/CityComponent/Transport/Airports.h"

std::unique_ptr<Transport> AirportsFactory::createTransport() {
    return std::make_unique<Airports>();
}