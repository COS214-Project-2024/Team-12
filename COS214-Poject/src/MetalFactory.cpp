#include "MetalFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "Gold.h" // Assuming Gold is a derived class of IncomeResourceProduct
#include "Steel.h" // Assuming Steel is a derived class of ConstructionResourceProduct

/**
 * @brief Constructor for the MetalFactory.
 *
 * Initializes a MetalFactory instance, used to produce metal-related resources
 * for income generation and construction.
 */
MetalFactory::MetalFactory() {
    std::cout << "Metal Factory created." << std::endl;
}

/**
 * @brief Destructor for the MetalFactory.
 *
 * Cleans up resources associated with the MetalFactory instance.
 */
MetalFactory::~MetalFactory() {
    std::cout << "Metal Factory deleted." << std::endl;
}

/**
 * @brief Creates an income-generating resource.
 *
 * This method creates and returns a `Gold` object, an income-generating resource.
 *
 * @param quantity The quantity of the resource to be produced.
 * @return A unique pointer to an `IncomeResourceProduct` representing `Gold`.
 */
std::unique_ptr<IncomeResourceProduct> MetalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Gold>(quantity, 20);  
}

/**
 * @brief Creates a construction resource.
 *
 * This method creates and returns a `Steel` object, a construction resource.
 *
 * @param quantity The quantity of the construction resource to be produced.
 * @return A unique pointer to a `ConstructionResourceProduct` representing `Steel`.
 */
std::unique_ptr<ConstructionResourceProduct> MetalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Steel>(quantity, 15);
}
