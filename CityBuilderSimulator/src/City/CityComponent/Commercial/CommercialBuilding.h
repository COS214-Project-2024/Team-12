#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "CollectTaxCommercial.h"
using namespace std;

class CommercialBuilding{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;
    
    


    public:
   virtual void accept(CollectTaxCommercial& TC)=0;
    virtual void payTax()=0;
};


#endif