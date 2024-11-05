#include "Shops.h"


void Shops::setShopsRate(double rate){
    shopsRate =rate;
}


void Shops::accept(CollectTaxCommercial& TC){
    TC.visit(this);
}


void Shops::payTax(){
    //increase money in government instance
    Government::getInstance().addMoney(price*shopsRate);

    // set taxPayed to true
    taxPayed=true;

    //reset tax to false after 30 seconds
        resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });
}

Shops::Shops(){

}