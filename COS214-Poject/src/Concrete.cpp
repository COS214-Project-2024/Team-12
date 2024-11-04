/**
 * @file Concrete.cpp
 * @brief Implementation of the Concrete class, representing a construction resource for use within the game.
 */

#include "Concrete.h"

/**
 * @brief Constructs a Concrete resource with a specified quantity and unit cost.
 * 
 * Initializes the concrete resource, setting its name to "Concrete" and
 * establishing the initial quantity and cost per unit.
 * 
 * @param quantity The amount of concrete available.
 * @param unitCost The cost per unit of concrete.
 */
Concrete::Concrete(int quantity, int unitCost)
    : ConstructionResourceProduct("Concrete", quantity, unitCost) {}

/**
 * @brief Destructor for the Concrete class.
 * 
 * Cleans up resources associated with the Concrete object.
 */
Concrete::~Concrete() {
    //std::cout << "Concrete resource destroyed." << std::endl;
}

/**
 * @brief Displays the status of the concrete resource.
 * 
 * Outputs details specific to the concrete resource, including its quantity,
 * unit cost, and total cost, to the console.
 */
void Concrete::displayStatus() {
    std::cout << "Resource: Concrete\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
