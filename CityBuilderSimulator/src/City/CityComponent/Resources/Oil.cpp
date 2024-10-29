#include "Oil.h"

// Constructor
Oil::Oil(int quantity, double marketValue)
    : IncomeResourceProduct("Oil", quantity, marketValue) {
 
}

// Destructor
Oil::~Oil() {
    std::cout << "Oil resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Oil
void Oil::displayStatus() {
    std::cout << "Resource: Oil\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
