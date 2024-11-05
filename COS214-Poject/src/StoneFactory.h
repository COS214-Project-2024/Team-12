#ifndef STONEFACTORY_H
#define STONEFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

/**
 * @class StoneFactory
 * @brief Factory class for creating stone resources, providing both income and construction products.
 * 
 * The `StoneFactory` class inherits from `ResourceFactory` and overrides methods to create 
 * `IncomeResourceProduct` and `ConstructionResourceProduct` objects representing stone resources.
 */
class StoneFactory : public ResourceFactory {
public:
    /**
     * @brief Constructor for StoneFactory.
     * 
     * Initializes any necessary components for the factory to create stone products.
     */
    StoneFactory();

    /**
     * @brief Destructor for StoneFactory.
     * 
     * Cleans up any allocated resources for the factory.
     */
    ~StoneFactory();

    /**
     * @brief Creates an income resource product representing stone.
     * 
     * @param quantity The quantity of stone for the income resource.
     * @return A unique pointer to an `IncomeResourceProduct` representing stone.
     */
    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;

    /**
     * @brief Creates a construction resource product representing stone.
     * 
     * @param quantity The quantity of stone for the construction resource.
     * @return A unique pointer to a `ConstructionResourceProduct` representing stone.
     */
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
