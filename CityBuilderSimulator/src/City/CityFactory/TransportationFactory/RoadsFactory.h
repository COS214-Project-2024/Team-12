#ifndef ROADSFACTORY_H
#define ROADSFACTORY_H

#include "TransportationFactory.h"
#include "CityComponent/Transport/Transport.h"

class RoadsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif