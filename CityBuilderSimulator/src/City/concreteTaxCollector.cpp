#include "concreteTaxCollector.h"


void ConcreteTaxCollector::visit(ResidentialBuilding* RB) {
   RB->payTax();
}

void ConcreteTaxCollector::visit(CommercialBuilding* CB) {
    CB->payTax();
}

void ConcreteTaxCollector::visit(ResidentialZoneComposite* Rzone){
    Rzone->payTax();
}