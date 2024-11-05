#include "OfficeFactory.h"
#include "Office.h"

/**
 * @brief Creates an instance of an Office building.
 * 
 * This method implements the createBuilding function defined in the
 * OfficeFactory class. It creates and returns a unique pointer to a new 
 * Office instance, allowing the management of Office buildings within the 
 * city simulation.
 * 
 * @return std::unique_ptr<CommercialBuilding> A unique pointer to the newly created Office.
 */
std::unique_ptr<CommercialBuilding> OfficeFactory::createBuilding() {
    return std::make_unique<Office>();
}
