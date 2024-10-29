#include "PlantFactory.h"
#include "../../CityComponent/Resources/Wood.h"
#include "../../CityComponent/Resources/Coal.h"

// Constructor
PlantFactory::PlantFactory() {
    std::cout << "Plant Factory created." << std::endl;
}

PlantFactory::~PlantFactory() {
    std::cout << "Plant Factory deleted." << std::endl;
}

// Method to create an income-generating resource
std::unique_ptr<IncomeResourceProduct> PlantFactory::createIncomeR(int quantity) {
    std::cout << "Creating income-generating resource with quantity: " << quantity << std::endl;
    return std::make_unique<Coal>(quantity, 12); 
}

// Method to create a construction resource
std::unique_ptr<ConstructionResourceProduct> PlantFactory::createConstructionR(int quantity) {
    std::cout << "Creating construction resource with quantity: " << quantity << std::endl;
    return std::make_unique<Wood>(quantity, 8); 
}
