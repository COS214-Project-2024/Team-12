#include "Stone.h"

// Constructor
Stone::Stone(int quantity, int unitCost)
    : ConstructionResourceProduct("Stone", quantity, unitCost) {
 
}

// Destructor
Stone::~Stone() {
    //std::cout << "Stone resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Stone
void Stone::displayStatus() {
    std::cout << "Resource: Stone\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
