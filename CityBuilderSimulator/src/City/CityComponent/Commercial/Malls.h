#ifndef MALLS_H
#define MALLS_H

#include <string>
#include "taxCollector.h"
#include "Government.h"
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
    Government* bank;
   

    public:
    void setMallRate(double rate);
    void accept(taxCollector& TC);
    void payTax();
};


#endif