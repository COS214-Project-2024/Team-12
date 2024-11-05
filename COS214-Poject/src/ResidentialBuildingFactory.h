#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include <memory>
#include "ResidentialBuilding.h"

/**
 * @brief Abstract Factory class for creating residential buildings.
 *
 * The ResidentialBuildingFactory class provides an interface for creating residential building
 * objects. Concrete factories derived from this class will implement the specific creation logic
 * for different types of residential buildings.
 */
class ResidentialBuildingFactory {
public:
    /**
     * @brief Creates a residential building.
     * @return A unique pointer to a ResidentialBuilding.
     *
     * This function is intended to be overridden in derived classes to create specific types
     * of residential buildings.
     */
    virtual std::unique_ptr<ResidentialBuilding> createBuilding() = 0;

    /**
     * @brief Virtual destructor for ResidentialBuildingFactory.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~ResidentialBuildingFactory() {}
};

#endif // RESIDENTIALFACTORY_H
