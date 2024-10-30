#ifndef TRAINSFACTORY_H
#define TRAINSFACTORY_H

#include "TransportationFactory.h"
#include "Transport.h"

class TrainsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif