#ifndef PUBLICTRANSITFACTORY_H
#define PUBLICTRANSITFACTORY_H

#include "../City/CityFactory/TransportationFactory/TransportationFactory.h"
#include "../City/CityComponent/Transport/Transport.h"

class PublicTransitFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif