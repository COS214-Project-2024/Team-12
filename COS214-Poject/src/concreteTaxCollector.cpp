// #include "concreteTaxCollector.h"
// #include "ZoneComposite.h"


// void ConcreteTaxCollector::visit(ResidentialBuilding* RB)  {
//     if (RB) {
//         double taxAmount = calculateResidentialTax(RB);
//         Government::getInstance().addMoney(taxAmount);
//         RB->payTax();
//     }
// }

// void ConcreteTaxCollector::visit(CommercialBuilding* CB)  {
//     if (CB) {
//         double taxAmount = calculateCommercialTax(CB);
//         Government::getInstance().addMoney(taxAmount);
//         CB->payTax();
//     }
// }

// void ConcreteTaxCollector::visit(ZoneComposite* Rzone) {
//     if (Rzone) {
//         Rzone->collectTaxes(this);
//     }
// }

// double ConcreteTaxCollector::calculateResidentialTax(ResidentialBuilding* RB) {
//     // Example tax calculation for residential buildings
//     // You might want to adjust this based on your specific needs
//     return RB->getPrice() * 0.05; // 5% tax rate
// }

// double ConcreteTaxCollector::calculateCommercialTax(CommercialBuilding* CB) {
//     // Example tax calculation for commercial buildings
//     return CB->getPrice() * 0.08; // 8% tax rate
//  }