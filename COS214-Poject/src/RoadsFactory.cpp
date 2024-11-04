#include "RoadsFactory.h"
#include "Roads.h"

/**
 * @brief Creates a new Roads transport object.
 * 
 * This method instantiates and returns a unique pointer to a new Roads object, 
 * which represents a type of transport infrastructure in the city simulation.
 * 
 * @return std::unique_ptr<Transport> A unique pointer to a Roads object.
 */
std::unique_ptr<Transport> RoadsFactory::createTransport() {
    return std::make_unique<Roads>();
}
