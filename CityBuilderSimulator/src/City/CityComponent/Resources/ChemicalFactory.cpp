#include "ChemicalFactory.h"

// Constructor
ChemicalFactory::ChemicalFactory() {
    std::cout << "Chemical Factory created." << std::endl;
}

ChemicalFactory::~ChemicalFactory() {
    std::cout << "Chemical Factory deleted." << std::endl;
}

// Method to create an income-generating resource
IncomeResourceProduct* ChemicalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
	IncomeResourceProduct* inc = new Oil(quantity,15);
    return inc;  // Example resource with unit cost of 15
}

// Method to create a construction resource
ConstructionResourceProduct* ChemicalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
	IncomeResourceProduct* inc = new Concrete(quantity,10);
    return inc;  
}
