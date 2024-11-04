#ifndef OFFICEFACTORY_H
#define OFFICEFACTORY_H

#include "CommercialFactory.h"
#include "CommercialBuilding.h"

/**
 * @class OfficeFactory
 * @brief Factory class for creating Office buildings.
 * 
 * The OfficeFactory class provides a method to create Office buildings, 
 * implementing the factory pattern for creating instances of the 
 * CommercialBuilding type.
 */
class OfficeFactory : public CommercialFactory {
public:
    /**
     * @brief Creates a new Office building.
     * 
     * @return A unique pointer to a new Office building.
     */
    std::unique_ptr<CommercialBuilding> createBuilding() override;
};

#endif
