#include "StoneFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "Diamonds.h"
#include "Stone.h"

/**
 * @brief Constructor for StoneFactory.
 * 
 * Initializes the StoneFactory and outputs a creation message to the console.
 */
StoneFactory::StoneFactory() {
    std::cout << "Stone Factory created." << std::endl;
}

/**
 * @brief Destructor for StoneFactory.
 * 
 * Outputs a deletion message to the console upon factory destruction.
 */
StoneFactory::~StoneFactory() {
    std::cout << "Stone Factory deleted." << std::endl;
}

/**
 * @brief Creates an income-generating resource.
 * 
 * This method generates a resource product for income, represented as Diamonds,
 * with the specified quantity and a default unit price.
 * 
 * @param quantity The quantity of the income-generating resource to be created.
 * @return A unique pointer to an `IncomeResourceProduct` representing Diamonds.
 */
std::unique_ptr<IncomeResourceProduct> StoneFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Diamonds>(quantity, 18);
}

/**
 * @brief Creates a construction resource.
 * 
 * This method generates a resource product for construction, represented as Stone,
 * with the specified quantity and a default unit price.
 * 
 * @param quantity The quantity of the construction resource to be created.
 * @return A unique pointer to a `ConstructionResourceProduct` representing Stone.
 */
std::unique_ptr<ConstructionResourceProduct> StoneFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Stone>(quantity, 14); 
}
