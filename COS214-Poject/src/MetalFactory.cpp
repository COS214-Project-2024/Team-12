#include "MetalFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "Gold.h" // Assuming Gold is a derived class of IncomeResourceProduct
#include "Steel.h" // Assuming Steel is a derived class of ConstructionResourceProduct

// Constructor
MetalFactory::MetalFactory() {
    std::cout << "Metal Factory created." << std::endl;
}

MetalFactory::~MetalFactory() {
    std::cout << "Metal Factory deleted." << std::endl;
}

// Method to create an income-generating resource
std::unique_ptr<IncomeResourceProduct> MetalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Gold>(quantity, 20);  
}

// Method to create a construction resource
std::unique_ptr<ConstructionResourceProduct> MetalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Steel>(quantity, 15);
}
