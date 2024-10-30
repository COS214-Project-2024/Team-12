#include "TrainsFactory.h"
#include "Trains.h"

std::unique_ptr<Transport> TrainsFactory::createTransport() {
    return std::make_unique<Trains>();
}