#ifndef SHOPS_H
#define SHOPs_H

#include <string>
#include "CollectTaxCommercial.h"
#include "Government.h"
using namespace std;



class Shops:public CommercialBuilding{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;
    double shopsRate;
    
    

    public:
    Shops();
    void setShopsRate(double rate);
    void accept(CollectTaxCommercial& TC);
    void payTax();
};


#endif