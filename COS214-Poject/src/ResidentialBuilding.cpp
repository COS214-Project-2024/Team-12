#include "ResidentialBuilding.h"
#include "UtilityFlyweight.h"
#include "taxCollector.h"
#include "NPCManager.h"
#include <iostream>

ResidentialBuilding::ResidentialBuilding(int bedrooms, double price,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : bedrooms(bedrooms), price(price), taxPaid(false),
        waterSupply(std::move(water)), powerSupply(std::move(power)), wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

void ResidentialBuilding::displayStatus() {
        std::cout << "Building Type: " << getBuildingType() << "\n"
                << "Bedrooms: " << bedrooms << "\n"
                << "Price: $" << price << "\n"
                << "Tax Status: " << (taxPaid ? "Paid" : "Unpaid") << "\n"
                << "Utilities Connected: " << (hasUtilities() ? "Yes" : "No") << "\n";
}

bool ResidentialBuilding::isTaxPaid() const {
        return taxPaid;
}

void ResidentialBuilding::accept(taxCollector* TC) {
    if (TC) {
        TC->visit(this);
    }
}

void ResidentialBuilding::setTaxPaid(bool paid) {
        taxPaid = paid;
        // Only affect happiness if there are NPCs
        if(paid && NPCManager::getInstance().getTotalNPCs()) {
                NPCManager::getInstance().setHappinessLevel(-2);
        }
}