#include "VisitCommercial.h"

 void VisitCommercial::visit(Office* office){
    office->payTax();

 }


void VisitCommercial::visit(Shops* shop){
    shop->payTax();

}



void VisitCommercial::visit(Malls* mall){
    mall->payTax();

}

VisitCommercial::VisitCommercial(){
    
}

