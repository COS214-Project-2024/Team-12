#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "ResidentialBuilding.h"

/**
 * @class HouseFactory
 * @brief Factory class for creating House objects.
 * 
 * The HouseFactory is a concrete factory class that implements the 
 * ResidentialBuildingFactory interface to produce House objects.
 */
class HouseFactory : public ResidentialBuildingFactory {
public:
    /**
     * @brief Creates a unique pointer to a new House object.
     * 
     * This function overrides the createBuilding method in ResidentialBuildingFactory 
     * to return a House, which is a specific type of ResidentialBuilding.
     * 
     * @return std::unique_ptr<ResidentialBuilding> A unique pointer to a newly created House object.
     */
    std::unique_ptr<ResidentialBuilding> createBuilding() override;
};

#endif
