#include "Shops.h"


void Shops::setShopsRate(double rate){
    shopsRate =rate;
}


void Shops::accept(taxCollector& TC){
    TC.visit(this);
}


void Shops::payTax(){
    bank->addMoney(price*shopsRate);
    taxPayed=true;
}


