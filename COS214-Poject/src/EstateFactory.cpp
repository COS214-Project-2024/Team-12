#include "EstateFactory.h"
#include "Estate.h"

/**
 * @brief Creates a new instance of an Estate building.
 * 
 * This method overrides the createBuilding method from the 
 * ResidentialBuildingFactory class to specifically create an 
 * instance of an Estate. It returns a unique pointer to the 
 * newly created Estate object.
 * 
 * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the newly created Estate building.
 */
std::unique_ptr<ResidentialBuilding> EstateFactory::createBuilding() {
    return std::make_unique<Estate>();
}
