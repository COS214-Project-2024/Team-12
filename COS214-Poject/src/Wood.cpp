#include "Wood.h"

/// @brief Constructs a Wood object with specified quantity and unit cost.
/// @param quantity The quantity of wood.
/// @param unitCost The unit cost of the wood.
Wood::Wood(int quantity, int unitCost)
    : ConstructionResourceProduct("Wood", quantity, unitCost) {
}

/// @brief Destructor for Wood.
Wood::~Wood() {
    // Uncomment if destruction message is needed:
    // std::cout << "Wood resource destroyed." << std::endl;
}

/// @brief Displays the current status of the wood resource.
/// 
/// Provides specific information for wood, including quantity, unit cost, and total cost.
void Wood::displayStatus() {
    std::cout << "Resource: Wood\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
