#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"
#include "taxCollector.h"
#include "CityComposite.h"
#include "Government.h"

class Estate : public ResidentialBuilding {
    private:
    CityComposite* city;
    bool taxPayed;
    double price;
    Government* bank;
public:
    Estate();
    Estate(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage,double price);
    void displayStatus();
    std::unique_ptr<ResidentialBuilding> clone() const;
    void accept(taxCollector* TC);
    void payTax();
};

#endif