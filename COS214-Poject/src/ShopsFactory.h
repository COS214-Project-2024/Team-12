#ifndef SHOPSFACTORY_H
#define SHOPSFACTORY_H

#include "CommercialFactory.h"
#include "CommercialBuilding.h"

/**
 * @class ShopsFactory
 * @brief Factory class for creating shop buildings.
 * 
 * ShopsFactory is a concrete implementation of CommercialFactory
 * that creates shop-type commercial buildings. This factory is used
 * to encapsulate the creation of shop buildings, adhering to the Abstract
 * Factory design pattern.
 */
class ShopsFactory : public CommercialFactory {
public:
    /**
     * @brief Creates a new shop building.
     * 
     * This method creates and returns a unique pointer to a shop-type
     * commercial building.
     * 
     * @return std::unique_ptr<CommercialBuilding> A unique pointer to the created shop building.
     */
    std::unique_ptr<CommercialBuilding> createBuilding();
};

#endif // SHOPSFACTORY_H
