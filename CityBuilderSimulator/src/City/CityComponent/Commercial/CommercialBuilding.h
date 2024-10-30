#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "../../../City/taxCollector.h"
#include "../CityComponent.h"
using namespace std;

class CommercialBuilding : public CityComponent{
    private:
    string state;
    double price;
    int numberOfEmployees;
    int Capacity;
    double size;
    bool taxPayed;
    


    public:

   virtual void accept(taxCollector& TC)=0;
    virtual void payTax()=0;

   
    std::string getBuildingType() override{
        return "Commercial Building";
    }

};


#endif