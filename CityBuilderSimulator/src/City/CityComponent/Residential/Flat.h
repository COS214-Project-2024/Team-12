#ifndef FLAT_H
#define FLAT_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"

class Flat : public ResidentialBuilding {
private:
CityComposite* city;
bool taxPayed;
public:
    Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void accept(taxCollector* TC);
    void payTax();
     
};

#endif