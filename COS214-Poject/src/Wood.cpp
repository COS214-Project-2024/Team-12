#include "Wood.h"

// Constructor
Wood::Wood(int quantity, int unitCost)
    : ConstructionResourceProduct("Wood", quantity, unitCost) {

}

// Destructor
Wood::~Wood() {
    //std::cout << "Wood resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Wood
void Wood::displayStatus() {
    std::cout << "Resource: Wood\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
