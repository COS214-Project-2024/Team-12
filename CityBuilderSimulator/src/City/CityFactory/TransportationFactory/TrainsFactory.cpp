#include "TrainsFactory.h"
#include "CityComponent/Transport/Trains.h"

std::unique_ptr<Transport> TrainsFactory::createTransport() {
    return std::make_unique<Trains>();
}