#ifndef RESIDENTIAL_ZONE_COMPOSITE_H
#define RESIDENTIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>
#include <algorithm>
#include "CityComposite.h"
#include "CollectTaxResidential.h"


class ResidentialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> buildings;
    double residentialTaxRate;
    CollectTaxResidential& sars;
   
bool taxPayed;

public:
    ResidentialZoneComposite(double taxRate, CollectTaxResidential& sarsR);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;
   void payTax();

    
    
};

#endif