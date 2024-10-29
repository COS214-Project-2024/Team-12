#include "Gold.h"

// Constructor
Gold::Gold(int quantity, double marketValue)
    : IncomeResourceProduct("Gold", quantity, marketValue) {
   
}

// Destructor
Gold::~Gold() {
    std::cout << "Gold resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Gold
void Gold::displayStatus() {
    std::cout << "Resource: Gold\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
