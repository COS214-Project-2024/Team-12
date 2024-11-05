#include "TrainsFactory.h"
#include "Trains.h"

/**
 * @brief Creates a new instance of the Trains transport.
 * 
 * This method implements the Factory Method pattern by creating and returning
 * a unique instance of the Trains class. The returned instance represents a
 * train transport with all its specific properties.
 * 
 * @return std::unique_ptr<Transport> A unique pointer to the newly created Trains instance.
 */
std::unique_ptr<Transport> TrainsFactory::createTransport() {
    return std::make_unique<Trains>();
}
