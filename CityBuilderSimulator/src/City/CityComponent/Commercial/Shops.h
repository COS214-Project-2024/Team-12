#ifndef SHOPS_H
#define SHOPs_H

#include <string>

#include "../../taxCollector.h"
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
    Government* bank;
    

    public:
    void setShopsRate(double rate);
    void accept(taxCollector& TC);
    void payTax();
};


#endif