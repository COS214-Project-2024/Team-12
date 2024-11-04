#include "HouseFactory.h"
#include "House.h"

/**
 * @brief Creates a unique pointer to a new House object.
 * 
 * This function overrides the createBuilding method in ResidentialBuildingFactory to return
 * a House, which is a specific type of ResidentialBuilding.
 * 
 * @return std::unique_ptr<ResidentialBuilding> A unique pointer to a newly created House object.
 */
std::unique_ptr<ResidentialBuilding> HouseFactory::createBuilding() {
    return std::make_unique<House>();
}
