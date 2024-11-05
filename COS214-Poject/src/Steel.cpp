#include "Steel.h"

/**
 * @brief Constructs a Steel object with specified quantity and unit cost.
 * 
 * Initializes the Steel resource with a given quantity and cost per unit.
 * 
 * @param quantity The initial quantity of Steel.
 * @param unitCost The cost per unit of Steel.
 */
Steel::Steel(int quantity, int unitCost)
    : ConstructionResourceProduct("Steel", quantity, unitCost){
    // Additional initialization can go here if needed
}

/**
 * @brief Destructor for Steel.
 * 
 * Cleans up any resources or states when a Steel object is destroyed.
 */
Steel::~Steel() {
    //std::cout << "Steel resource destroyed." << std::endl;
}

/**
 * @brief Displays the current status of the Steel resource.
 * 
 * Provides detailed information about the quantity, unit cost, and total cost of the Steel.
 */
void Steel::displayStatus() {
    std::cout << "Resource: Steel\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
