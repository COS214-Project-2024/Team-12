#ifndef FLAT_H
#define FLAT_H

#include "ResidentialBuilding.h"

#include "taxCollector.h"
#include "CityComposite.h"


class Flat : public ResidentialBuilding {
private:
CityComposite* city;
bool taxPayed;
double rate;
Government* bank;

public:
    Flat();
    Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::shared_ptr<ResidentialBuilding> clone() const;
    void setFlatRate(double rate);
    void accept(taxCollector* TC);
    void payTax();
     
};

#endif