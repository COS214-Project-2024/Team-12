#include "Concrete.h"

// Constructor
Concrete::Concrete(int quantity, int unitCost)
    : ConstructionResourceProduct("Concrete", quantity, unitCost) {
 
}

// Destructor
Concrete::~Concrete() {
    std::cout << "Concrete resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Concrete
void Concrete::displayStatus() {
    std::cout << "Resource: Concrete\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
