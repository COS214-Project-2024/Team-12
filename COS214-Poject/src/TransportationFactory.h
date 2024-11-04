#ifndef TRANSPORTATIONFACTORY_H
#define TRANSPORTATIONFACTORY_H

#include <memory>
#include "Transport.h"

/**
 * @brief Abstract Factory class for creating transportation objects.
 * 
 * The TransportationFactory defines an interface for creating various types of
 * Transport objects. Derived classes will implement the specific transport
 * creation logic.
 */
class TransportationFactory {
public:
    /**
     * @brief Creates a transport object.
     * 
     * This pure virtual function must be overridden by derived factory classes
     * to instantiate specific types of transport objects.
     * 
     * @return A unique pointer to a Transport object.
     */
    virtual std::unique_ptr<Transport> createTransport() = 0;

    /**
     * @brief Virtual destructor for TransportationFactory.
     * 
     * Ensures proper cleanup of derived factory instances when deleted
     * through a pointer to the base class.
     */
    virtual ~TransportationFactory() {}
};

#endif
