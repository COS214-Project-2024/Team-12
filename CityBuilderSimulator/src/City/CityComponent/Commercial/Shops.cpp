#include "Shops.h"


void Shops::setShopsRate(double rate){
    shopsRate =rate;
}


void Shops::accept(CollectTaxCommercial& TC){
    TC.visit(this);
}


void Shops::payTax(){
    Government::getInstance().addMoney(price*shopsRate);
    taxPayed=true;

    //reset tax to false
        resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });
}

Shops::Shops(){

}