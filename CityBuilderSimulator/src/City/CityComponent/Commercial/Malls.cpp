#include "Malls.h"


void Malls::setMallRate(double rate){
    MallsRate =rate;
}


void Malls::accept(taxCollector& TC){
    TC.visit(this);
}


void Malls::payTax(){
    bank->addMoney(price*MallsRate);
    taxPayed=true;
}