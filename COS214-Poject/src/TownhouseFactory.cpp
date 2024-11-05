#include "TownhouseFactory.h"
#include "Townhouse.h"

/**
 * @brief Creates a new instance of a townhouse building.
 * 
 * This function overrides the createBuilding function in the ResidentialBuildingFactory
 * interface. It creates and returns a unique pointer to a Townhouse instance.
 * 
 * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the created townhouse.
 */
std::unique_ptr<ResidentialBuilding> TownhouseFactory::createBuilding() {
    return std::make_unique<Townhouse>();
}
