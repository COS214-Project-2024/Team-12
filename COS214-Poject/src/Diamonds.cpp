#include "Diamonds.h"

// Constructor
Diamonds::Diamonds(int quantity, double marketValue)
    : IncomeResourceProduct("Diamonds", quantity, marketValue) {
    // Additional initialization can go here if needed
}

// Destructor
Diamonds::~Diamonds() {
   // std::cout << "Diamonds resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Diamonds
void Diamonds::displayStatus() {
    std::cout << "Resource: Diamonds\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
