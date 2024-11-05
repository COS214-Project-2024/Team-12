#include "PoliceStationFactory.h"
#include "PoliceStation.h"

/**
 * @brief Creates a new PoliceStation object.
 * 
 * This method overrides the createPublicService function from the 
 * PublicServiceFactory interface, returning a unique pointer to a new 
 * instance of PoliceStation.
 * 
 * @return A unique pointer to the newly created PoliceStation object.
 */
std::unique_ptr<PublicService> PoliceStationFactory::createPublicService() {
    return std::make_unique<PoliceStation>();
}
