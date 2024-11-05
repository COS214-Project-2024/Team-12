#include "Oil.h"

/**
 * @brief Constructor for the Oil resource.
 * 
 * Initializes an instance of the Oil resource with the specified quantity 
 * and market value. It sets the name of the resource to "Oil" and initializes 
 * the base class attributes using the constructor of IncomeResourceProduct.
 * 
 * @param quantity The initial quantity of the oil resource.
 * @param marketValue The market value per unit of the oil resource.
 */
Oil::Oil(int quantity, double marketValue)
    : IncomeResourceProduct("Oil", quantity, marketValue) {
}

/**
 * @brief Destructor for the Oil resource.
 * 
 * Cleans up any resources held by the Oil object. The destructor may be
 * extended in the future to include additional cleanup logic.
 */
Oil::~Oil() {
   // std::cout << "Oil resource destroyed." << std::endl;
}

/**
 * @brief Displays the current status of the Oil resource.
 * 
 * Outputs the name, quantity, market value per unit, and total value of the
 * oil resource to the standard output. This provides a comprehensive summary
 * of the resource's current state.
 */
void Oil::displayStatus() {
    std::cout << "Resource: Oil\n"
              << "Quantity: " << getQuantity() << "\n"
              << "Market Value per Unit: $" << getMarketValue() << "\n"
              << "Total Value: $" << calculateIncome() << "\n" << std::endl;
}
