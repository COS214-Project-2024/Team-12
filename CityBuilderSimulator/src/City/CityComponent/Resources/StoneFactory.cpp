#include "StoneFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "Diamonds.h"   
#include "Stone.h"     

// Constructor
StoneFactory::StoneFactory() {
    std::cout << "Stone Factory created." << std::endl;
}

StoneFactory::~StoneFactory() {
    std::cout << "Stone Factory deleted." << std::endl;
}

// Method to create an income-generating resource
std::unique_ptr<IncomeResourceProduct> StoneFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Diamonds>(quantity, 18);
}

// Method to create a construction resource
std::unique_ptr<ConstructionResourceProduct> StoneFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Stone>(quantity, 14); 
}
