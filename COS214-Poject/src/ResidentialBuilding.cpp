#include "ResidentialBuilding.h"
#include "UtilityFlyweight.h"
#include "taxCollector.h"
#include "NPCManager.h"
#include <iostream>

/**
 * @brief Constructs a ResidentialBuilding with specified attributes and utilities.
 * @param bedrooms Number of bedrooms in the building.
 * @param price Price of the building.
 * @param water Shared pointer to the water utility.
 * @param power Shared pointer to the power utility.
 * @param waste Shared pointer to the waste management utility.
 * @param sewage Shared pointer to the sewage management utility.
 */
ResidentialBuilding::ResidentialBuilding(int bedrooms, double price,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : bedrooms(bedrooms), price(price), taxPaid(false),
        waterSupply(std::move(water)), powerSupply(std::move(power)), 
        wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

/**
 * @brief Displays the status of the residential building, including utility connections and tax status.
 */
void ResidentialBuilding::displayStatus() {
    std::cout << "Building Type: " << getBuildingType() << "\n"
              << "Bedrooms: " << bedrooms << "\n"
              << "Price: $" << price << "\n"
              << "Tax Status: " << (taxPaid ? "Paid" : "Unpaid") << "\n"
              << "Utilities Connected: " << (hasUtilities() ? "Yes" : "No") << "\n";
}

/**
 * @brief Checks if the tax has been paid for this building.
 * @return True if the tax is paid, false otherwise.
 */
bool ResidentialBuilding::isTaxPaid() const {
    return taxPaid;
}

/**
 * @brief Accepts a taxCollector visitor to collect taxes.
 * @param TC Pointer to the taxCollector visiting the building.
 */
void ResidentialBuilding::accept(taxCollector* TC) {
    if (TC) {
        TC->visit(this);
    }
}

/**
 * @brief Sets the tax-paid status and affects NPC happiness if applicable.
 * @param paid True if tax has been paid, false otherwise.
 */
void ResidentialBuilding::setTaxPaid(bool paid) {
    taxPaid = paid;
    // Only affect happiness if there are NPCs
    if (paid && NPCManager::getInstance().getTotalNPCs()) {
        NPCManager::getInstance().setHappinessLevel(-2);
    }
}
