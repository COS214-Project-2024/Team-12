#include "Flat.h"


Flat::Flat():ResidentialBuilding(2, 10000.00, nullptr, nullptr, nullptr, nullptr) {
        
}

Flat::Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(2, 10000.00, water, power, waste, sewage) {
                
        }

void Flat::displayStatus(){
    std::cout << "Flat Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Flat::clone() const {
        return std::make_unique<Flat>(*this);
}

void Flat::accept(CollectTaxResidential& TC){
        TC.visit(this);
}


void Flat::payTax(){
        if(hasGreenTechnology()){
        rate -= 0.3;
    }
    
    Government::getInstance().addMoney(price*rate);
    taxPayed=true;

        //reset tax to false
        resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });

}

void Flat::setFlatRate(double taxRate){
        rate= taxRate;
}