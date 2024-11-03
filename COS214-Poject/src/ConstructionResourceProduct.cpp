#include "ConstructionResourceProduct.h"

// Constructor with parameters
ConstructionResourceProduct::ConstructionResourceProduct(std::string name, int quantity, int unitCost)
    : name(name), quantity(quantity), unitCost(unitCost) {}

// Default constructor
ConstructionResourceProduct::~ConstructionResourceProduct()
{}

// Method to consume a specified amount of the resource
void ConstructionResourceProduct::ConsumeResource(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        std::cout << "Consumed " << amount << " units of " << name << ". Remaining: " << quantity << std::endl;
    } else {
        std::cout << "Not enough " << name << " available to consume. Available: " << quantity << std::endl;
    }
}

// Method to display the current status of the resource
void ConstructionResourceProduct::displayStatus() {
    std::cout << "Resource: " << name << "\nQuantity: " << quantity 
              << "\nUnit Cost: $" << unitCost 
              << "\nTotal Value: $" << getTotalCost() << "\n" << std::endl;
}

// Method to calculate and return the total cost of the available resource
int ConstructionResourceProduct::getTotalCost() const {
    return quantity * unitCost;
}

int ConstructionResourceProduct::getUnitCost() const {
    return quantity * unitCost;
}

// Method to get the current quantity of the resource
int ConstructionResourceProduct::getQuantity() const {
    return quantity;
}

// Method to add a specified quantity to the resource
void ConstructionResourceProduct::replenish(int amount) {
    quantity += amount;
    std::cout << "Replenished " << amount << " units of " << name << ". Total: " << quantity << std::endl;
}


/* double ConstructionResourceProduct::getTaxRevenue()
{
     return quantity * 0.2;
} */


bool ConstructionResourceProduct::isReadyForCollection() 
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