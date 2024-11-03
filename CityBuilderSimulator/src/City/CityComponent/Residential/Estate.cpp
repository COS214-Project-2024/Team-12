#include "Estate.h"

Estate::Estate() : ResidentialBuilding(6, 50000.00, nullptr, nullptr, nullptr, nullptr) {
    
}

Estate::Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : ResidentialBuilding(6, 50000.00, water, power, waste, sewage) {
            
        }

void Estate::displayStatus(){
    std::cout << "Estate Status:\n";
    ResidentialBuilding::displayStatus();
}



std::unique_ptr<ResidentialBuilding> Estate::clone() const {
    return std::make_unique<Estate>(*this);
}


void Estate::setEstateRate(double taxRate){

     rate= taxRate;

 }

 void Estate::accept(CollectTaxResidential& TC){
    TC.visit(this);

}



void Estate::payTax(){
    if(hasGreenTechnology()){
        rate -= 0.3;
    }
    Government::getInstance().addMoney(price*rate);
    taxPayed=true;


    //reset tax to false after 30 seconds
    resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });
    
}