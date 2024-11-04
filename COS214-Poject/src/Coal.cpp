#include "Coal.h"

// Constructor
Coal::Coal(int quantity, double marketValue)
    : IncomeResourceProduct("Coal", quantity, marketValue) {
   
}

// Destructor
Coal::~Coal() {
   // std::cout << "Coal resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Coal
void Coal::displayStatus() {
    std::cout << "Resource: Coal\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
