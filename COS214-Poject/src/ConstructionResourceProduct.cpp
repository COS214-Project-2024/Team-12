#include "ConstructionResourceProduct.h"

/**
 * @brief Constructs a ConstructionResourceProduct with specified name, quantity, and unit cost.
 * @param name The name of the resource.
 * @param quantity The initial quantity of the resource.
 * @param unitCost The cost per unit of the resource.
 */
ConstructionResourceProduct::ConstructionResourceProduct(std::string name, int quantity, int unitCost)
    : name(name), quantity(quantity), unitCost(unitCost) {}

/**
 * @brief Destructor for ConstructionResourceProduct.
 */
ConstructionResourceProduct::~ConstructionResourceProduct() {}

/**
 * @brief Consumes a specified amount of the resource, decreasing the quantity.
 * @param amount The amount to consume.
 */
void ConstructionResourceProduct::ConsumeResource(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
        std::cout << "Consumed " << amount << " units of " << name << ". Remaining: " << quantity << std::endl;
    } else {
        std::cout << "Not enough " << name << " available to consume. Available: " << quantity << std::endl;
    }
}

/**
 * @brief Displays the current status of the resource, including its name, quantity, unit cost, and total value.
 */
void ConstructionResourceProduct::displayStatus() {
    std::cout << "Resource: " << name << "\nQuantity: " << quantity 
              << "\nUnit Cost: $" << unitCost 
              << "\nTotal Value: $" << getTotalCost() << "\n" << std::endl;
}

/**
 * @brief Calculates and returns the total cost of the available resource.
 * @return The total cost, calculated as quantity * unit cost.
 */
int ConstructionResourceProduct::getTotalCost() const {
    return quantity * unitCost;
}

/**
 * @brief Retrieves the unit cost of the resource.
 * @return The unit cost of the resource.
 */
int ConstructionResourceProduct::getUnitCost() const {
    return unitCost;
}

/**
 * @brief Gets the current quantity of the resource.
 * @return The current quantity of the resource.
 */
int ConstructionResourceProduct::getQuantity() const {
    return quantity;
}

/**
 * @brief Replenishes the resource by adding a specified amount to the quantity.
 * @param amount The amount to add to the current quantity.
 */
void ConstructionResourceProduct::replenish(int amount) {
    quantity += amount;
    std::cout << "Replenished " << amount << " units of " << name << ". Total: " << quantity << std::endl;
}

/**
 * @brief Checks if the resource is ready for collection based on a minimum threshold.
 * @return True if the resource quantity is above or equal to the threshold, otherwise false.
 */
bool ConstructionResourceProduct::isReadyForCollection() {
    if (quantity >= 150) {
        readyForCollection = true;
    } else {
        readyForCollection = false;
    }
    return readyForCollection;
}
