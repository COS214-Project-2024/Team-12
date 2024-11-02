#include "CommercialBuilding.h"

// Implementation of the accept method
void CommercialBuilding::accept(taxCollector& TC) {
    // Call the tax collection method on this building, allowing TC to apply tax logic.
    TC.collectTax(*this);  // Assuming taxCollector has a `collectTax` method that takes a CommercialBuilding.
}

// Implementation of the payTax method
void CommercialBuilding::payTax() {
    if (!taxPayed) {
        // Set taxPaid to true once the tax is paid
        taxPayed = true;
        std::cout << "Tax has been paid for this building.\n";
    } else {
        std::cout << "Tax is already paid.\n";
    }
}
