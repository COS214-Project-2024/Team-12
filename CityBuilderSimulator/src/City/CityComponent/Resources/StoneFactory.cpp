#include "StoneFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>

// Constructor
StoneFactory::StoneFactory() {
    std::cout << "Stone Factory created." << std::endl;
}

// Destructor
StoneFactory::~StoneFactory() {
    std::cout << "Stone Factory destroyed." << std::endl;
}

// Method to create an income-generating resource (e.g., Refined Stone)
IncomeResourceProduct* StoneFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource (Refined Stone) with quantity: " << quantity << std::endl;
	IncomeResourceProduct* inc = new Diamonds(quantity);
	return inc;
   // return new IncomeResourceProduct("Refined Stone", quantity, 25);  // Example unit cost for Refined Stone
}

// Method to create a construction resource (e.g., Stone)
ConstructionResourceProduct* StoneFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource (Stone) with quantity: " << quantity << std::endl;
		ConstructionResourceProduct* inc = new Stone(quantity);
	return inc;
   // return new ConstructionResourceProduct("Stone", quantity, 8);  // Example unit cost for Stone
}
