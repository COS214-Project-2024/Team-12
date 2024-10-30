#ifndef AIRPORTSFACTORY_H
#define AIRPORTSFACTORY_H

#include "TransportationFactory.h"
#include "Transport.h"

class AirportsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif