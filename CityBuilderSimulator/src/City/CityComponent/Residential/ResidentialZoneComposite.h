#ifndef RESIDENTIAL_ZONE_COMPOSITE_H
#define RESIDENTIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>
#include <algorithm>
#include "CityComposite.h"
#include "taxCollector.h"


class ResidentialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> buildings;
    double residentialTaxRate;
    taxCollector* sars;

    bool taxPayed;


public:
    ResidentialZoneComposite(double taxRate);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;
    void accept(taxCollector* TC);
   void payTax();


    //double getTaxRevenue() override;

    std::string getBuildingType() override{
        return "Residential type";
    }

    void accept(taxCollector* TC);
    void payTax();

    
};

#endif