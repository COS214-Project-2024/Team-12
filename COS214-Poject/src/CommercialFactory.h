#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <memory>
#include "CommercialBuilding.h"

/**
 * @class CommercialFactory
 * @brief Abstract factory class for creating commercial buildings.
 * 
 * Provides an interface for creating different types of commercial buildings, 
 * allowing subclasses to define the specific type of commercial building created.
 */
class CommercialFactory {
public:
    /**
     * @brief Creates a commercial building.
     * 
     * This pure virtual function must be implemented by derived classes 
     * to create a specific type of commercial building.
     * 
     * @return A unique pointer to a newly created CommercialBuilding.
     */
    virtual std::unique_ptr<CommercialBuilding> createBuilding() = 0;

    /**
     * @brief Virtual destructor for the CommercialFactory class.
     */
    virtual ~CommercialFactory() {}
};

#endif
