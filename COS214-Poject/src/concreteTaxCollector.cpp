#include "concreteTaxCollector.h"
#include "ZoneComposite.h"


void ConcreteTaxCollector::visit(ResidentialBuilding* RB) {
   RB->payTax();
}

void ConcreteTaxCollector::visit(CommercialBuilding* CB) {
    CB->payTax();
}

void ConcreteTaxCollector::visit(ZoneComposite* Rzone){
    Rzone->payTax();

}