#include "Office.h"




void Office::setOfficeRate(double rate){
    officeRate =rate;
}


void Office::accept(CollectTaxCommercial& TC){
    TC.visit(this);
}


void Office::payTax(){
    //bank.addMoney(price*officeRate);
    Government::getInstance().addMoney(price*officeRate);
    taxPayed=true;

    //reset tax to false
        resetTax = std::async(std::launch::async, [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            taxPayed = false;
            std::cout << "Tax status reset to false after 30 seconds.\n";
        });
}


Office::Office(){
    
}


