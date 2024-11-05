#ifndef FIRESTATIONFACTORY_H
#define FIRESTATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

/**
 * @brief Factory class for creating FireStation objects.
 * 
 * Inherits from the PublicServiceFactory and provides the 
 * functionality to create instances of FireStation.
 */
class FireStationFactory : public PublicServiceFactory {
public:
    /**
     * @brief Creates a new FireStation object.
     * 
     * This method returns a unique pointer to a newly created 
     * FireStation instance.
     * 
     * @return A unique pointer to a PublicService (FireStation).
     */
    std::unique_ptr<PublicService> createPublicService();
};

#endif
