#include "Office.h"

void Office::setOfficeRate(double rate){
    officeRate =rate;
}


void Office::accept(taxCollector& TC){
    TC.visit(this);
}


void Office::payTax(){
    bank->addMoney(price*officeRate);
    taxPayed=true;
}