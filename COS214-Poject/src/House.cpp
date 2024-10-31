#include "House.h"

House::House():ResidentialBuilding(3, 15000.0, nullptr, nullptr, nullptr, nullptr) {}

House::House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(3, 15000.0, water, power, waste, sewage) {}

void House::displayStatus() {
    std::cout << "House Status:\n";
    ResidentialBuilding::displayStatus();
}



std::shared_ptr<ResidentialBuilding> House::clone() const{
    return std::make_shared<House>(*this);
}

 void House::setHouseTax(double taxRate){
     rate= taxRate;

 }

 void House::accept(taxCollector* TC){
    TC->visit(this);

}



void House::payTax(){
    //bank->addMoney(price*rate);
    taxPayed=true;
    
}