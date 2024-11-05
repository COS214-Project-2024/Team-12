#ifndef ROADSFACTORY_H
#define ROADSFACTORY_H

#include "TransportationFactory.h"
#include "Transport.h"

/**
 * @brief Factory class for creating Road transport objects.
 * 
 * RoadsFactory is a concrete implementation of the TransportationFactory. 
 * It provides a method to create Road transport objects, following the Factory Pattern.
 */
class RoadsFactory : public TransportationFactory {
public:
    /**
     * @brief Creates a Road transport object.
     * 
     * @return std::unique_ptr<Transport> A unique pointer to a new Road transport object.
     */
    std::unique_ptr<Transport> createTransport();
};

#endif // ROADSFACTORY_H
