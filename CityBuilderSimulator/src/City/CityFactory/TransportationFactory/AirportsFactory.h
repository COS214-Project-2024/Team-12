#ifndef AIRPORTSFACTORY_H
#define AIRPORTSFACTORY_H

#include "../City/CityFactory/TransportationFactory/TransportationFactory.h"
#include "../City/CityComponent/Transport/Transport.h"

class AirportsFactory : public TransportationFactory {
public:
    std::unique_ptr<Transport> createTransport();
};

#endif