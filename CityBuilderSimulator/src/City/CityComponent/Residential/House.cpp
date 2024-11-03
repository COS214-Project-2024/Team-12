#include "House.h"

House::House():ResidentialBuilding(3, 15000.0, nullptr, nullptr, nullptr, nullptr) {
    
}

House::House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(3, 15000.0, water, power, waste, sewage) {
            
        }

void House::displayStatus() {
    std::cout << "House Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> House::clone() const{
    return std::make_unique<House>(*this);
}

 void House::setHouseTaxRate(double taxRate){
     rate= taxRate;

 }

 void House::accept(CollectTaxResidential& TC){
    TC.visit(this);

}



void House::payTax(){
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