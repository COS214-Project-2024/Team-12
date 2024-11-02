#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
#include "CollectTaxResidential.h"
#include "Government.h"

class Townhouse : public ResidentialBuilding {
private:
double price;
bool taxPayed;
double rate;
public:
    Townhouse();
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
   
    std::unique_ptr<ResidentialBuilding> clone() const;
     void setTownhouseRate(double rate);
     void accept(CollectTaxResidential& TC);
    void payTax();
};

#endif