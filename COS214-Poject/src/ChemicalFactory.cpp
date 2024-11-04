/**
 * @file ChemicalFactory.cpp
 * @brief Implementation of the ChemicalFactory class for creating resources.
 * 
 * This file provides the implementation for methods in the ChemicalFactory class, 
 * which creates income-generating and construction resources.
 */

#include "ChemicalFactory.h"
#include "Oil.h"      
#include "Concrete.h" 

/**
 * @brief Constructs a new ChemicalFactory object.
 * 
 * Outputs a message indicating the creation of a ChemicalFactory instance.
 */
ChemicalFactory::ChemicalFactory() {
    std::cout << "Chemical Factory created." << std::endl;
}

/**
 * @brief Destroys the ChemicalFactory object.
 * 
 * Outputs a message indicating the deletion of a ChemicalFactory instance.
 */
ChemicalFactory::~ChemicalFactory() {
    std::cout << "Chemical Factory deleted." << std::endl;
}

/**
 * @brief Creates an income-generating resource.
 * 
 * This method creates an income resource of type `Oil` with a specified quantity.
 * 
 * @param quantity The quantity of the income resource to create.
 * @return A unique pointer to an `IncomeResourceProduct` instance representing the income resource.
 */
std::unique_ptr<IncomeResourceProduct> ChemicalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Oil>(quantity, 15);  
}

/**
 * @brief Creates a construction resource.
 * 
 * This method creates a construction resource of type `Concrete` with a specified quantity.
 * 
 * @param quantity The quantity of the construction resource to create.
 * @return A unique pointer to a `ConstructionResourceProduct` instance representing the construction resource.
 */
std::unique_ptr<ConstructionResourceProduct> ChemicalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Concrete>(quantity, 10); 
}
