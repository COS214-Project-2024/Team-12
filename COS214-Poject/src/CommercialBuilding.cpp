#include "CommercialBuilding.h"
#include "NPCManager.h"
#include "taxCollector.h"
#include <iostream>

// Constructor implementation without default arguments
CommercialBuilding::CommercialBuilding(double price,
                      std::shared_ptr<UtilityFlyweight> water,
                      std::shared_ptr<UtilityFlyweight> power,
                      std::shared_ptr<UtilityFlyweight> waste,
                      std::shared_ptr<UtilityFlyweight> sewage)
    : price(price), taxPaid(false),
      waterSupply(std::move(water)), powerSupply(std::move(power)),
      wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

void CommercialBuilding::displayStatus() {
    std::cout << "Building Type: " << getBuildingType() << "\n"
              << "Price: $" << price << "\n"
              << "Tax Status: " << (taxPaid ? "Paid" : "Unpaid") << "\n"
              << "Utilities Connected: " << getUtilityCoverage() << "/4\n";
}

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

std::string CommercialBuilding::getBuildingType() const {
    return "Commercial Building";
}

int CommercialBuilding::getUtilityCoverage() const {
    int coverage = 0;
    if (waterSupply) coverage++;
    if (powerSupply) coverage++;
    if (wasteManagement) coverage++;
    if (sewageManagement) coverage++;
    return coverage;
}