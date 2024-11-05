#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include <memory>
#include "LandMark.h"

/**
 * @brief Abstract factory class for creating landmark objects.
 * 
 * The `LandMarkFactory` class provides an interface for creating different types
 * of landmarks in the city simulation. Specific landmark types should be created
 * by concrete factories that inherit from this interface.
 */
class LandMarkFactory {
public:
    /**
     * @brief Pure virtual function to create a landmark.
     * 
     * This function should be implemented by derived classes to create specific types of landmarks.
     * @return A unique pointer to the created `LandMark` object.
     */
    virtual std::unique_ptr<LandMark> createLandMark() = 0;

    /**
     * @brief Virtual destructor for the `LandMarkFactory` class.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~LandMarkFactory() {}
};

#endif // LANDMARKFACTORY_H
