#ifndef MALLSFACTORY_H
#define MALLSFACTORY_H

#include "CommercialFactory.h"
#include "CommercialBuilding.h"

/**
 * @class MallsFactory
 * @brief Factory class for creating Mall buildings.
 *
 * This class implements the factory pattern to create instances of
 * `Mall`, a specific type of `CommercialBuilding`.
 */
class MallsFactory : public CommercialFactory {
public:
    /**
     * @brief Creates an instance of a Mall.
     *
     * Overrides the `createBuilding` function to provide a specific
     * implementation for creating a `Mall` object.
     *
     * @return A unique pointer to a `CommercialBuilding` instance representing a `Mall`.
     */
    std::unique_ptr<CommercialBuilding> createBuilding();
};

#endif
