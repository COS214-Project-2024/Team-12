#include "Townhouse.h"

Townhouse::Townhouse() : ResidentialBuilding(4, 30000.00, nullptr, nullptr, nullptr, nullptr) {}

Townhouse::Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(4, 30000.00, water, power, waste, sewage) {}

void Townhouse::displayStatus(){
    std::cout << "Townhouse Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Townhouse::clone() const {
    return std::make_unique<Townhouse>(*this);
}

void Townhouse::setTownhouseRate(double taxRate){
     rate= taxRate;

 }

 void Townhouse::accept(taxCollector* TC){
    TC->visit(this);

}



void Townhouse::payTax(){
    bank->addMoney(price*rate);
    taxPayed=true;
    
}