#ifndef ROADSFACTORY_H
#define ROADSFACTORY_H

#include "../City/CityFactory/TransportationFactory/TransportationFactory.h"
#include "../City/CityComponent/Transport/Transport.h"

class RoadsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif