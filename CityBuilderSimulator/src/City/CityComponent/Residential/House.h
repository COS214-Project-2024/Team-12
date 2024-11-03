#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include "CollectTaxResidential.h"
#include "CityComposite.h"
#include "Government.h"


class House : public ResidentialBuilding {
private:
double rate;
bool taxPayed;


//double price;
public:
    House();
    House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void setHouseTaxRate(double rate);
    void accept(CollectTaxResidential& TC);
    void payTax();
     
};

#endif