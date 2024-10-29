#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"
#include "CityComposite.h"
#include "taxCollector.h"

class Townhouse : public ResidentialBuilding {
private:
CityComposite* city;
bool taxPayed;
public:
    Townhouse(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
   
    std::unique_ptr<ResidentialBuilding> clone() const;
     
     void accept(taxCollector* TC);
    void payTax();
};

#endif