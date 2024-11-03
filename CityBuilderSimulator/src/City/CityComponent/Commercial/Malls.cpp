#include "Malls.h"


void Malls::setMallRate(double rate){
    MallsRate =rate;
}


void Malls::accept(CollectTaxCommercial& TC){
    TC.visit(this);
}


void Malls::payTax(){
    Government::getInstance().addMoney(price*MallsRate);
    taxPayed=true;

    //reset tax to false
        resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });
}

Malls::Malls(){
    
}