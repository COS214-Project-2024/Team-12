#ifndef FLATFACTORY_H
#define FLATFACTORY_H

#include "ResidentialBuildingFactory.h"

/**
 * @brief Factory class for creating Flat residential buildings.
 * 
 * The FlatFactory class inherits from ResidentialBuildingFactory and 
 * provides an implementation for creating instances of Flat buildings.
 */
class FlatFactory : public ResidentialBuildingFactory {
public:
    /**
     * @brief Creates a unique pointer to a ResidentialBuilding of type Flat.
     * 
     * This method instantiates a Flat object and returns it as a 
     * unique pointer.
     * 
     * @return std::unique_ptr<ResidentialBuilding> A unique pointer to the 
     * created Flat object.
     */
    std::unique_ptr<ResidentialBuilding> createBuilding();
};

#endif
