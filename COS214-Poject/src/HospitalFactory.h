/**
 * @file HospitalFactory.h
 * @brief Declaration of the HospitalFactory class for creating Hospital objects.
 *
 * This file defines the HospitalFactory class, which is responsible for creating
 * instances of the Hospital class, a type of public service in the game.
 */

#ifndef HOSPITALFACTORY_H
#define HOSPITALFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

/**
 * @class HospitalFactory
 * @brief A factory class for creating Hospital instances.
 *
 * The HospitalFactory class derives from PublicServiceFactory and implements
 * a method to create Hospital objects. This allows for the encapsulation
 * of the object creation logic, making it easier to manage dependencies
 * and variations in the construction of Hospital objects.
 */
class HospitalFactory : public PublicServiceFactory {
public:
    /**
     * @brief Creates a new instance of a PublicService, specifically a Hospital.
     * 
     * @return A unique pointer to the newly created Hospital object.
     */
    std::unique_ptr<PublicService> createPublicService();
};

#endif // HOSPITALFACTORY_H
