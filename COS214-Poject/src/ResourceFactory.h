#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <memory>

/**
 * @brief Abstract Factory class for creating resources.
 *
 * The ResourceFactory class defines the interface for creating
 * income-generating and construction-based resources. Derived classes
 * will implement the specific creation logic for different types of resources.
 */
class ResourceFactory {
public:
    /**
     * @brief Default constructor for ResourceFactory.
     */
    ResourceFactory() = default;

    /**
     * @brief Virtual destructor for ResourceFactory, allowing derived classes to clean up resources.
     */
    virtual ~ResourceFactory() = default;

    /**
     * @brief Creates an income-generating resource.
     * @param quantity The quantity of the income resource to create.
     * @return A unique pointer to an IncomeResourceProduct.
     */
    virtual std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) = 0;

    /**
     * @brief Creates a construction resource.
     * @param quantity The quantity of the construction resource to create.
     * @return A unique pointer to a ConstructionResourceProduct.
     */
    virtual std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) = 0;
};

#endif // RESOURCEFACTORY_H
