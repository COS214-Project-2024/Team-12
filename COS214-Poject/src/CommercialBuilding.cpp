#include "CommercialBuilding.h"
#include <iostream>

// Constructor implementation without default arguments
CommercialBuilding::CommercialBuilding(double initialPrice, int initialCapacity)
    : price(initialPrice), taxPayed(false), capacity(initialCapacity) {}

// void CommercialBuilding::accept(taxCollector* TC) {
//     if (TC) TC->visit(this);
// }

// void CommercialBuilding::payTax() {
//     taxPayed = true;
// }

std::string CommercialBuilding::getBuildingType() {
    return "Commercial Building";
}

void CommercialBuilding::displayStatus() {
    std::cout << "Commercial Building\n"
              << "Price: $" << price << "\n"
              << "Capacity: " << capacity << " workers\n"
              << "Tax Status: " << (taxPayed ? "Paid" : "Unpaid") << "\n";
}