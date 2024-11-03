#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "CollectTaxCommercial.h"
using namespace std;
#include <future>
#include <chrono>
#include <atomic>
#include <iostream>

class CommercialBuilding{
    protected:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
   std::atomic<bool> taxPayed{false};
    std::future<void> resetTax;
    
    


    public:
   virtual void accept(CollectTaxCommercial& TC)=0;
    virtual void payTax()=0;
};


#endif