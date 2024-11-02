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
}

Shops::Shops(){
    
}