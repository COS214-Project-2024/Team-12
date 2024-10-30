#include "IncomeResourceProduct.h"

// Constructor
IncomeResourceProduct::IncomeResourceProduct(string name, int quantity, double marketValue)
    : name(name), quantity(quantity), marketValue(marketValue) {}

// Destructor
IncomeResourceProduct::~IncomeResourceProduct() {
    cout << "IncomeResourceProduct (" << name << ") destroyed." << endl;
}

// Method to consume a specified amount of the resource
void IncomeResourceProduct::consumeResources(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        cout << "Consumed " << amount << " units of " << name << ". Remaining: " << quantity << endl;
    } else {
        cout << "Not enough " << name << " available to consume." << endl;
    }
}

// Method to calculate total income generated by the resource
double IncomeResourceProduct::calculateIncome()  const{
    return quantity * marketValue;
}

// Getter for market value
double IncomeResourceProduct::getMarketValue() const {
    return marketValue;
}

// Method to display resource details
void IncomeResourceProduct::displayStatus() const {
    cout << "Income Resource: " << name
         << "\nQuantity: " << quantity
         << "\nMarket Value per Unit: $" << marketValue
         << "\nTotal Value: $" << calculateIncome() << "\n" << endl;
}

int IncomeResourceProduct::getQuantity() const
{
      return quantity; 
}

/* double IncomeResourceProduct::getTaxRevenue()
{
      return quantity * marketValue * 0.1;
} */


bool IncomeResourceProduct::isReadyForCollection() 
{
    if(quantity >= 150)
    {
         readyForCollection = true;
    }
    else{
        readyForCollection = false;
    }
    return readyForCollection;
}

// Method to add a specified quantity to the resource
void IncomeResourceProduct::replenish(int amount) {
    quantity += amount;
    std::cout << "Replenished " << amount << " units of " << name << ". Total: " << quantity << std::endl;
}
