#include "ChemicalFactory.h"
#include "../../CityComponent/Resources/Oil.h"      
#include "../../CityComponent/Resources/Concrete.h" 


// Constructor
ChemicalFactory::ChemicalFactory() {
    std::cout << "Chemical Factory created." << std::endl;
}

ChemicalFactory::~ChemicalFactory() {
    std::cout << "Chemical Factory deleted." << std::endl;
}

// Method to create an income-generating resource
std::unique_ptr<IncomeResourceProduct> ChemicalFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Oil>(quantity, 15);  
}

// Method to create a construction resource
std::unique_ptr<ConstructionResourceProduct> ChemicalFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Concrete>(quantity, 10); 
}
