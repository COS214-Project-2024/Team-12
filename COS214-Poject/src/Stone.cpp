#include "Stone.h"

/**
 * @brief Constructs a Stone object with specified quantity and unit cost.
 * 
 * Initializes the Stone resource with a name, quantity, and unit cost.
 * 
 * @param quantity The initial quantity of Stone.
 * @param unitCost The cost per unit of Stone.
 */
Stone::Stone(int quantity, int unitCost)
    : ConstructionResourceProduct("Stone", quantity, unitCost) { 
    // Initialization is handled in the initializer list
}

/**
 * @brief Destructor for Stone.
 * 
 * This is where any specific cleanup would be done for Stone objects.
 */
Stone::~Stone() {
    // Uncomment for debugging:
    // std::cout << "Stone resource destroyed." << std::endl;
}

/**
 * @brief Displays the current status of the Stone resource.
 * 
 * Outputs detailed information about the Stone resource, including its type,
 * quantity, unit cost, and total cost.
 */
void Stone::displayStatus() {
    std::cout << "Resource: Stone\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
