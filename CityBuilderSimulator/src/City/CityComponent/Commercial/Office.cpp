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
}


Office::Office(){
    
}
