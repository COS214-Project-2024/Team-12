#include "RoadsFactory.h"
#include "Roads.h"

std::unique_ptr<Transport> RoadsFactory::createTransport() {
    return std::make_unique<Roads>();
}