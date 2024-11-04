#ifndef TRAINSFACTORY_H
#define TRAINSFACTORY_H

#include "TransportationFactory.h"
#include "Transport.h"

/**
 * @brief Factory class for creating train transport instances.
 * 
 * TrainsFactory is a concrete factory that implements the TransportationFactory
 * interface. This class is responsible for creating and returning instances of
 * train transports using the Factory Method pattern.
 */
class TrainsFactory : public TransportationFactory {
public:
    /**
     * @brief Create a new train transport instance.
     * 
     * Implements the Factory Method to create a unique instance of a train
     * transport. This method encapsulates the instantiation details of the
     * transport and returns a pointer to the created object.
     * 
     * @return A unique pointer to a new Transport instance representing a train.
     */
    std::unique_ptr<Transport> createTransport();
};

#endif
