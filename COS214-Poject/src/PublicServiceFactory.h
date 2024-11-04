/**
 * @file PublicServiceFactory.h
 * @brief Abstract Factory class for creating PublicService objects.
 */

#ifndef PUBLICSERVICEFACTORY_H
#define PUBLICSERVICEFACTORY_H

#include <memory>
#include "PublicService.h"

/**
 * @class PublicServiceFactory
 * @brief An abstract factory class for creating instances of PublicService.
 * 
 * This factory provides an interface for creating public service buildings in the city simulation.
 * Derived classes must implement the `createPublicService` function to provide specific types of public services.
 */
class PublicServiceFactory {
public:
    /**
     * @brief Pure virtual function to create a PublicService object.
     * @return A unique pointer to the created PublicService object.
     */
    virtual std::unique_ptr<PublicService> createPublicService() = 0;

    /**
     * @brief Virtual destructor for PublicServiceFactory.
     */
    virtual ~PublicServiceFactory() {}
};

#endif // PUBLICSERVICEFACTORY_H
