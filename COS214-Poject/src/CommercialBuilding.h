#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "taxCollector.h"
#include "CityComponent.h"
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

   void accept(taxCollector* TC) override;
   void payTax();

   
    std::string getBuildingType() override{
        return "Commercial Building";
    }

    void displayStatus() override;

};


#endif