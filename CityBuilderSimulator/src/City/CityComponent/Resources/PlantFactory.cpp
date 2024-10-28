#include "PlantFactory.h"

#include <iostream>

// Constructor
PlantFactory::PlantFactory() {
    std::cout << "Plant Factory created." << std::endl;
}

// Destructor
PlantFactory::~PlantFactory() {
    std::cout << "Plant Factory destroyed." << std::endl;
}

// Method to create an income-generating resource (e.g., Timber)
IncomeResourceProduct* PlantFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource (Timber) with quantity: " << quantity << std::endl;
	ConstructionResourceProduct* inc = Coal(quantity);
	return inc;
   // return new IncomeResourceProduct("Timber", quantity, 20);  // Example unit cost for Timber
}

// Method to create a construction resource (e.g., Wood)
ConstructionResourceProduct* PlantFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource (Wood) with quantity: " << quantity << std::endl;
	ConstructionResourceProduct* inc = Wood(quantity);
	return inc;
   // return new ConstructionResourceProduct("Wood", quantity, 5);  // Example unit cost for Wood
}
