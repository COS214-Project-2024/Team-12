#include "ShopsFactory.h"
#include "Shops.h"

/**
 * @brief Creates a new shop building.
 * 
 * This method instantiates a Shops object, which represents a commercial
 * building of type shop, and returns a unique pointer to the created building.
 * 
 * @return std::unique_ptr<CommercialBuilding> A unique pointer to the created Shops object.
 */
std::unique_ptr<CommercialBuilding> ShopsFactory::createBuilding() {
    return std::make_unique<Shops>();
}
