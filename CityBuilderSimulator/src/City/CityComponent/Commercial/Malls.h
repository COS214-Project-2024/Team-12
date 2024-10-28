#ifndef MALLS_H
#define MALLS_H

#include <string>
#include "taxCollector.h"
using namespace std;

class Malls: public CommercialBuilding{
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