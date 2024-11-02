#include "visitResidential.h"


 void VisitResidential::visit(House* house){
    house->payTax();
 }


void VisitResidential::visit(Estate* estate){
   estate->payTax();
}


void VisitResidential::visit(Townhouse* townhouse){
   townhouse->payTax();
}


void VisitResidential::visit(Flat* flat){
   flat->payTax();
}
     
