#include "concreteTaxCollector.h"
#include "ZoneComposite.h"


void ConcreteTaxCollector::visit(ResidentialBuilding* RB)  {
    if (!RB) return;
    double taxAmount = RB->getPrice() * 0.05;   // 5% tax for residential
    Government::getInstance().addMoney(taxAmount);
    RB->setTaxPaid(true);
}

void ConcreteTaxCollector::visit(CommercialBuilding* CB)  {
    if (!CB) return;
    double taxAmount = CB->getPrice() * 0.08;
    Government::getInstance().addMoney(taxAmount);
    CB->setTaxPaid(true);
}

void ConcreteTaxCollector::visit(ZoneComposite* zone) {
    if(!zone) return;
    for (auto& building : zone->getBuildings()) {
        building->accept(this);
    }
}