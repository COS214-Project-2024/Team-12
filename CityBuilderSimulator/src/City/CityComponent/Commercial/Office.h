#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include "taxCollector.h"
using namespace std;

class Office: public CommercialBuilding{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;

    public:
    void accept(taxCollector& TC);
    void payTax();
};


#endif