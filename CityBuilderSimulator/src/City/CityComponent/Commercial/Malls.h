#ifndef MALLS_H
#define MALLS_H

#include <string>
#include "CollectTaxCommercial.h"
#include "Government.h"
#include "CommercialBuilding.h"
using namespace std;

class Malls: public CommercialBuilding{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;
    double MallsRate;
    
   

    public:
    void setMallRate(double rate);
    void accept(CollectTaxCommercial& TC);
    void payTax();
    Malls();
};


#endif