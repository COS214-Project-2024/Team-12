#ifndef COMMERCIAL_ZONE_COMPOSITE_H
#define COMMERCIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>
#include "CollectTaxCommercial.h"


class CommercialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> commercialbuildings;
    double commercialTaxRate;
    CollectTaxCommercial& sars;
public:
    CommercialZoneComposite(double taxRate, CollectTaxCommercial& sarsR);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;

    
    virtual void payTax();

    
};

#endif