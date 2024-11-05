#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "ResidentialBuilding.h"

/**
 * @brief Factory class for creating Townhouse residential buildings.
 * 
 * This class implements the ResidentialBuildingFactory interface to
 * produce instances of townhouses.
 */
class TownhouseFactory : public ResidentialBuildingFactory {
public:
    /**
     * @brief Creates a new instance of a townhouse building.
     * 
     * Implements the Factory Method to produce a specific type of residential
     * building, which in this case is a townhouse.
     * 
     * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the created townhouse.
     */
    std::unique_ptr<ResidentialBuilding> createBuilding() override;
};

#endif
