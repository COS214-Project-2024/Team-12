#include "Gold.h"

// Constructor
/**
 * @brief Constructs a Gold object with specified quantity and market value.
 * 
 * Initializes the Gold resource with its name, quantity, and market value.
 * 
 * @param quantity The amount of gold.
 * @param marketValue The market value of a single unit of gold.
 */
Gold::Gold(int quantity, double marketValue)
    : IncomeResourceProduct("Gold", quantity, marketValue) {
}

// Destructor
/**
 * @brief Destructor for the Gold object.
 * 
 * Cleans up resources associated with the Gold object. 
 */
Gold::~Gold() {
    // std::cout << "Gold resource destroyed." << std::endl;
}

// Override displayStatus to provide specific information for Gold
/**
 * @brief Displays the status of the gold resource.
 * 
 * Outputs the quantity, market value per unit, and total value of the gold resource to the console.
 */
void Gold::displayStatus() {
    std::cout << "Resource: Gold\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
