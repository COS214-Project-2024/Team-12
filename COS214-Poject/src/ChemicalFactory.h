#ifndef CHEMICALFACTORY_H
#define CHEMICALFACTORY_H

#include "ResourceFactory.h"        
#include "IncomeResourceProduct.h"    
#include "ConstructionResourceProduct.h" 
#include <iostream>
#include <memory>

/**
 * @class ChemicalFactory
 * @brief A factory class for creating chemical resources used in construction and income generation.
 * 
 * The `ChemicalFactory` class specializes in producing income-generating and construction resources.
 * It inherits from `ResourceFactory` and implements the factory methods to create specific types
 * of resource products.
 */
class ChemicalFactory : public ResourceFactory {
public:
    /**
     * @brief Constructs a new ChemicalFactory object.
     * 
     * Initializes any required state for the chemical resource factory.
     */
    ChemicalFactory();

    /**
     * @brief Destroys the ChemicalFactory object.
     * 
     * Cleans up resources allocated by the factory.
     */
    ~ChemicalFactory();

    /**
     * @brief Creates an income-generating resource.
     * 
     * @param quantity The amount of income resource to create.
     * @return A unique pointer to an `IncomeResourceProduct` instance.
     */
    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;

    /**
     * @brief Creates a construction resource.
     * 
     * @param quantity The amount of construction resource to create.
     * @return A unique pointer to a `ConstructionResourceProduct` instance.
     */
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
