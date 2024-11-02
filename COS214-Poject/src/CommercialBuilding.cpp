#include "CommercialBuilding.h"
#include <iostream>

// Constructor implementation without default arguments
CommercialBuilding::CommercialBuilding(double initialPrice, int initialCapacity)
    : price(initialPrice), taxPaid(false), capacity(initialCapacity) {}

void CommercialBuilding::accept(taxCollector* TC) {
    if (TC) TC->visit(this);
}

void CommercialBuilding::setTaxPaid(bool paid) {
    taxPaid = true;
    if(paid) {
        // Commercial tax payments might affect employment rate
        Government::getInstance().increaseEmploymentRate(1.0);
    }
}

std::string CommercialBuilding::getBuildingType() {
    return "Commercial Building";
}

void CommercialBuilding::displayStatus() {
    std::cout << "Commercial Building\n"
              << "Price: $" << price << "\n"
              << "Capacity: " << capacity << " workers\n"
              << "Tax Status: " << (taxPaid ? "Paid" : "Unpaid") << "\n";
}