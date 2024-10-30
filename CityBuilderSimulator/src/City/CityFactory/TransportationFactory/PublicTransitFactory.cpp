#include "../src/City/CityFactory/TransportationFactory/PublicTransitFactory.h"
#include "../src/City/CityComponent/Transport/PublicTransit.h"

std::unique_ptr<Transport> PublicTransitFactory::createTransport() {
    return std::make_unique<PublicTransit>();
}