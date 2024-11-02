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
}

Malls::Malls(){
    
}