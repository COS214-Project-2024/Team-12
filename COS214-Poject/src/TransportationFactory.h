#ifndef TRANSPORTATIONFACTORY_H
#define TRANSPORTATIONFACTORY_H

#include <memory>
#include "Transport.h"

class TransportationFactory {
public:
    virtual std::unique_ptr<Transport> createTransport() = 0;
    virtual ~TransportationFactory() {}
};

#endif