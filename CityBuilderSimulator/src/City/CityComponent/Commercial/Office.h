#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include "taxCollector.h"
#include "Government.h"
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
    Government* bank;
  

    public:
    void setOfficeRate(double rate);
    void accept(taxCollector& TC);
    void payTax();
};


#endif