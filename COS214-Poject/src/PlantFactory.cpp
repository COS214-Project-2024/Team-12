#include "PlantFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "Wood.h"
#include "Coal.h"

// Constructor
/**
 * @brief Constructs a PlantFactory.
 * 
 * This constructor initializes the PlantFactory and outputs a message indicating
 * that the factory has been created.
 */
PlantFactory::PlantFactory() {
    std::cout << "Plant Factory created." << std::endl;
}

/**
 * @brief Destroys the PlantFactory.
 * 
 * This destructor cleans up the PlantFactory resources and outputs a message
 * indicating that the factory has been deleted.
 */
PlantFactory::~PlantFactory() {
    std::cout << "Plant Factory deleted." << std::endl;
}

// Method to create an income-generating resource
/**
 * @brief Creates an income-generating resource.
 * 
 * This method creates an instance of an income-generating resource (Coal) 
 * with the specified quantity.
 * 
 * @param quantity The quantity of the income-generating resource to create.
 * @return A unique pointer to the created IncomeResourceProduct (Coal).
 */
std::unique_ptr<IncomeResourceProduct> PlantFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Coal>(quantity, 12); 
}

// Method to create a construction resource
/**
 * @brief Creates a construction resource.
 * 
 * This method creates an instance of a construction resource (Wood) 
 * with the specified quantity.
 * 
 * @param quantity The quantity of the construction resource to create.
 * @return A unique pointer to the created ConstructionResourceProduct (Wood).
 */
std::unique_ptr<ConstructionResourceProduct> PlantFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Wood>(quantity, 8); 
}
