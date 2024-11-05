#ifndef POLICESTATIONFACTORY_H
#define POLICESTATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

/**
 * @class PoliceStationFactory
 * @brief Factory class to create PoliceStation instances.
 *
 * This class inherits from PublicServiceFactory and provides 
 * the implementation for creating instances of PoliceStation.
 */
class PoliceStationFactory : public PublicServiceFactory {
public:
    /**
     * @brief Creates a new PoliceStation object.
     * 
     * This method overrides the createPublicService function 
     * from the PublicServiceFactory interface, returning a 
     * unique pointer to a new instance of PoliceStation.
     * 
     * @return A unique pointer to the newly created PoliceStation object.
     */
    std::unique_ptr<PublicService> createPublicService();
};

#endif
