#include "MallsFactory.h"
#include "Malls.h"

/**
 * @brief Creates a new instance of a Mall.
 * 
 * This function overrides the `createBuilding` method from `CommercialBuildingFactory`
 * to provide a specific implementation for creating a `Mall`.
 * 
 * @return A unique pointer to a `CommercialBuilding` instance representing a `Mall`.
 */
std::unique_ptr<CommercialBuilding> MallsFactory::createBuilding() {
    return std::make_unique<Malls>();
}
