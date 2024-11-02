#ifndef FLAT_H
#define FLAT_H

#include "ResidentialBuilding.h"
#include "CollectTaxResidential.h"
#include "CityComposite.h"
#include "Government.h"

class Flat : public ResidentialBuilding {
private:
CityComposite* city;
bool taxPayed;
double rate;


public:
    Flat();
    Flat(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void setFlatRate(double rate);
    void accept(CollectTaxResidential& TC);
    void payTax();
     
};

#endif