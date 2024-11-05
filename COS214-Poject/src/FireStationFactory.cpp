#include "FireStationFactory.h"
#include "FireStation.h"

/**
 * @brief Creates a new FireStation object.
 * 
 * This function utilizes the FireStation class to instantiate a 
 * new FireStation object and returns it as a unique pointer 
 * to the PublicService base class.
 * 
 * @return A unique pointer to a PublicService representing 
 * the newly created FireStation.
 */
std::unique_ptr<PublicService> FireStationFactory::createPublicService() {
    return std::make_unique<FireStation>();
}
