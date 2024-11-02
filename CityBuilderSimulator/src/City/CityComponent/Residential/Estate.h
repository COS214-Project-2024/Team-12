#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"
#include "CollectTaxResidential.h"
#include "CityComposite.h"
#include "Government.h"

class Estate : public ResidentialBuilding {
    private:
    CityComposite* city;
    bool taxPayed;
    double price;
    double rate;
   
public:
    Estate();
    Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void setEstateRate(double rate);
    void accept(CollectTaxResidential& TC);
    void payTax();
};

#endif