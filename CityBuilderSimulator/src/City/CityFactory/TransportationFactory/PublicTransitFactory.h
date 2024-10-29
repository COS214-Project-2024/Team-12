#ifndef PUBLICTRANSITFACTORY_H
#define PUBLICTRANSITFACTORY_H

#include "TransportationFactory.h"
#include "CityComponent/Transport/Transport.h"

class PublicTransitFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif