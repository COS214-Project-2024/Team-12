#ifndef TRAINSFACTORY_H
#define TRAINSFACTORY_H

#include "../City/CityFactory/TransportationFactory/TransportationFactory.h"
#include "../CityComponent/Transport/Transport.h"

class TrainsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif