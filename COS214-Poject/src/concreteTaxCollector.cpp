/**
 * @file concreteTaxCollector.cpp
 * @brief Implementation of the ConcreteTaxCollector class, defining tax collection behaviors for residential and commercial buildings, as well as zones.
 */

#include "concreteTaxCollector.h"
#include "ZoneComposite.h"

/**
 * @brief Collects tax from a residential building.
 * 
 * Calculates a 5% tax based on the building’s price and adds it to the government’s funds. 
 * If no NPCs are present in the building, no tax is collected.
 * 
 * @param RB Pointer to the ResidentialBuilding from which to collect tax.
 */
void ConcreteTaxCollector::visit(ResidentialBuilding* RB)  {
    if (!RB) return;

    // Temporary solution until NPC system is implemented
    auto& npcManager = NPCManager::getInstance();
    if(npcManager.getTotalNPCs() == 0) {
        std::cout << "Building is vacant - no tax collected\n";
        return;
    }

    double taxAmount = RB->getPrice() * 0.05;   // 5% tax for residential
    Government::getInstance().addMoney(taxAmount);
    RB->setTaxPaid(true);
}

/**
 * @brief Collects tax from a commercial building.
 * 
 * Calculates an 8% tax based on the building’s price and adds it to the government’s funds.
 * 
 * @param CB Pointer to the CommercialBuilding from which to collect tax.
 */
void ConcreteTaxCollector::visit(CommercialBuilding* CB)  {
    if (!CB) return;
    double taxAmount = CB->getPrice() * 0.08;
    Government::getInstance().addMoney(taxAmount);
    CB->setTaxPaid(true);
}

/**
 * @brief Collects tax from all buildings within a zone.
 * 
 * Iterates through the buildings in the given ZoneComposite and collects tax from each 
 * by invoking the appropriate tax collection method.
 * 
 * @param zone Pointer to the ZoneComposite containing buildings to collect tax from.
 */
void ConcreteTaxCollector::visit(ZoneComposite* zone) {
    if(!zone) return;
    for (auto& building : zone->getBuildings()) {
        building->accept(this);
    }
}
