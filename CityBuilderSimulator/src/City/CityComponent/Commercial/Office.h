#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include "CollectTaxCommercial.h"
#include "Government.h"
#include "CommercialBuilding.h"
using namespace std;


class Office: public CommercialBuilding{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;
    double officeRate;
    
  

    public:
    void setOfficeRate(double rate);
    void accept(CollectTaxCommercial& TC);
    void payTax();
    Office();
};


#endif