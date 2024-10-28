#include "PublicTransitFactory.h"
#include "CityComponent/Transport/PublicTransit.h"

std::unique_ptr<Transport> PublicTransitFactory::createTransport() {
    return std::make_unique<PublicTransit>();
}