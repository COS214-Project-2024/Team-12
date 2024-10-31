/* #ifndef PUBLICTRANSITFACTORY_H
#define PUBLICTRANSITFACTORY_H

#include "TransportationFactory.h"
#include "Transport.h"
#include "PublicTransit.h"

class PublicTransitFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif */