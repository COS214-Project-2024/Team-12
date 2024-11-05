/**
 * @file Coal.cpp
 * @brief Implementation of the Coal class, representing a coal resource in the game.
 */

#include "Coal.h"

/**
 * @brief Constructs a Coal object with a specified quantity and market value.
 * 
 * Initializes the coal resource with a name, quantity, and market value.
 * 
 * @param quantity The initial quantity of coal.
 * @param marketValue The market value per unit of coal.
 */
Coal::Coal(int quantity, double marketValue)
    : IncomeResourceProduct("Coal", quantity, marketValue) {
}

/**
 * @brief Destructor for the Coal class.
 * 
 * Cleans up resources for the coal object if needed.
 */
Coal::~Coal() {
    // std::cout << "Coal resource destroyed." << std::endl;
}

/**
 * @brief Displays the current status of the coal resource.
 * 
 * Outputs details specific to coal, including quantity, market value per unit, 
 * and total calculated value.
 */
void Coal::displayStatus() {
    std::cout << "Resource: Coal\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
