#ifndef ESTATEFACTORY_H
#define ESTATEFACTORY_H

#include "ResidentialBuildingFactory.h"
#include "ResidentialBuilding.h"

/**
 * @brief The EstateFactory class is responsible for creating Estate buildings.
 *
 * This class inherits from the ResidentialBuildingFactory and provides
 * a concrete implementation for creating instances of ResidentialBuilding
 * specifically for the Estate type.
 */
class EstateFactory : public ResidentialBuildingFactory {
public:
    /**
     * @brief Creates a new instance of an Estate building.
     * 
     * This method returns a unique pointer to a ResidentialBuilding 
     * that is specifically an Estate.
     * 
     * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the newly created Estate building.
     */
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif
