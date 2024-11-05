#include "Diamonds.h"

/**
 * @brief Constructs a Diamonds resource with specified quantity and market value.
 * 
 * Initializes the Diamonds resource with a given quantity and market value per unit.
 * 
 * @param quantity The amount of diamonds available.
 * @param marketValue The market value per unit of diamonds.
 */
Diamonds::Diamonds(int quantity, double marketValue)
    : IncomeResourceProduct("Diamonds", quantity, marketValue) {
    // Additional initialization can go here if needed
}

/**
 * @brief Destructor for the Diamonds resource.
 * 
 * Cleans up resources associated with the Diamonds object upon destruction.
 */
Diamonds::~Diamonds() {
   // std::cout << "Diamonds resource destroyed." << std::endl;
}

/**
 * @brief Displays the current status of the Diamonds resource.
 * 
 * Outputs the resource's name, quantity, market value per unit, and total calculated income
 * to the console.
 */
void Diamonds::displayStatus() {
    std::cout << "Resource: Diamonds\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
