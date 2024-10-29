#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"
#include "Government.h"


class House : public ResidentialBuilding {
private:
double rate;
bool taxPayed;
Government* bank;
//double price;
public:
    House();
    House(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void setHouseTax(double rate);
    void accept(taxCollector* TC);
    void payTax();
     
};

#endif