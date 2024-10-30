#include "Flat.h"

Flat::Flat():ResidentialBuilding(2, 10000.00, nullptr, nullptr, nullptr, nullptr) {}

Flat::Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(2, 10000.00, water, power, waste, sewage) {}

void Flat::displayStatus(){
    std::cout << "Flat Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Flat::clone() const {
        return std::make_unique<Flat>(*this);
}

void Flat::accept(taxCollector* TC){
        TC->visit(this);
}


void Flat::payTax(){
        bank->addMoney(price*rate);
    taxPayed=true;

}

void Flat::setFlatRate(double taxRate){
        rate= taxRate;
}