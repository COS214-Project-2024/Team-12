#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

/**
 * @class PlantFactory
 * @brief A factory class for creating resources related to plants.
 * 
 * The PlantFactory class is responsible for creating income-generating
 * and construction resources, specifically Coal and Wood.
 */
class PlantFactory : public ResourceFactory {
public:
    /**
     * @brief Constructs a PlantFactory.
     * 
     * Initializes the PlantFactory instance.
     */
    PlantFactory();

    /**
     * @brief Destroys the PlantFactory.
     * 
     * Cleans up resources used by the PlantFactory.
     */
    ~PlantFactory();

    /**
     * @brief Creates an income-generating resource.
     * 
     * @param quantity The quantity of the income-generating resource to create.
     * @return A unique pointer to the created IncomeResourceProduct.
     */
    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;

    /**
     * @brief Creates a construction resource.
     * 
     * @param quantity The quantity of the construction resource to create.
     * @return A unique pointer to the created ConstructionResourceProduct.
     */
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
