#include "MetalFactory.h"


// Constructor
MetalFactory::MetalFactory() {
    std::cout << "Metal Factory created." << std::endl;
}

// Destructor
MetalFactory::~MetalFactory() {
    std::cout << "Metal Factory destroyed." << std::endl;
}

// Method to create an income-generating resource (e.g., Gold)
IncomeResourceProduct* MetalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource (Gold) with quantity: " << quantity << std::endl;
	IncomeResourceProduct* inc = new Gold(quantity);
    return inc;  // Example unit cost for Gold
}

// Method to create a construction resource (e.g., Steel)
ConstructionResourceProduct* MetalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource (Steel) with quantity: " << quantity << std::endl;
	ConstructionResourceProduct* inc = new Steel(quantity);
    return inc;  // Example unit cost for Steel
}
