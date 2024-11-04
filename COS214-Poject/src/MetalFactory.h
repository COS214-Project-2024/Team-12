#ifndef METALFACTORY_H
#define METALFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

/**
 * @class MetalFactory
 * @brief A factory class for creating metal-related resources for income generation and construction.
 *
 * The MetalFactory is derived from ResourceFactory and specializes in creating
 * resources related to metals, such as gold for income and steel for construction.
 */
class MetalFactory : public ResourceFactory {
public:
    /**
     * @brief Constructor for MetalFactory.
     *
     * Initializes a MetalFactory instance that can create metal-related resources.
     */
    MetalFactory();

    /**
     * @brief Destructor for MetalFactory.
     *
     * Cleans up resources associated with the MetalFactory instance.
     */
    ~MetalFactory();

    /**
     * @brief Creates an income-generating metal resource.
     *
     * Creates and returns a `Gold` object, an income-generating resource, with a specified quantity.
     *
     * @param quantity The quantity of the income resource to be produced.
     * @return A unique pointer to an `IncomeResourceProduct` representing `Gold`.
     */
    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;

    /**
     * @brief Creates a construction metal resource.
     *
     * Creates and returns a `Steel` object, a construction resource, with a specified quantity.
     *
     * @param quantity The quantity of the construction resource to be produced.
     * @return A unique pointer to a `ConstructionResourceProduct` representing `Steel`.
     */
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
