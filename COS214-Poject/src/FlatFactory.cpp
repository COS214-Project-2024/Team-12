#include "FlatFactory.h"
#include "Flat.h"

/**
 * @brief Creates a unique pointer to a Flat residential building.
 * 
 * This function instantiates a Flat object and returns it as a 
 * unique pointer. The created Flat building has default attributes
 * as specified in its constructor.
 * 
 * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the 
 * created Flat object.
 */
std::unique_ptr<ResidentialBuilding> FlatFactory::createBuilding() {
    return std::make_unique<Flat>();
}
