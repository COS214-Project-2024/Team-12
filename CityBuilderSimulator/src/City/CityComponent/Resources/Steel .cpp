#include "Steel.h"

// Constructor
Steel::Steel(int quantity, int unitCost, double tensileStrength)
    : ConstructionResourceProduct("Steel", quantity, unitCost){
    // Additional initialization can go here if needed
}

// Destructor
Steel::~Steel() {
    std::cout << "Steel resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Steel
void Steel::displayStatus() {
    std::cout << "Resource: Steel\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Unit Cost: $" << getUnitCost() << "\n"
              << "Tensile Strength: " << tensileStrength << " MPa\n"
              << "Total Cost: $" << getTotalCost() << "\n" << std::endl;
}
