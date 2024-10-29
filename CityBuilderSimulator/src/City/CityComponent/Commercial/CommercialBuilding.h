#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "../src/City/taxCollector.h"
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
    void accept(taxCollector& TC);
    void payTax();
};


#endif