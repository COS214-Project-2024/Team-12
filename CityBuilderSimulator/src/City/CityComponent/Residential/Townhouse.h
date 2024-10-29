#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "Government.h"

class Townhouse : public ResidentialBuilding {
private:
Government* bank;
double price;
bool taxPayed;
public:
    Townhouse();
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage,double price);
    void displayStatus();
   
    std::unique_ptr<ResidentialBuilding> clone() const;
     
     void accept(taxCollector* TC);
    void payTax();
};

#endif