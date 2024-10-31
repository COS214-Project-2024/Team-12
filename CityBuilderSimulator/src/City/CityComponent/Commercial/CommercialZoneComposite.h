#ifndef COMMERCIAL_ZONE_COMPOSITE_H
#define COMMERCIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>
#include "taxCollector.h"


class CommercialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> commercialbuildings;
    double commercialTaxRate;
    taxCollector& sars;
public:
    CommercialZoneComposite(double taxRate, taxCollector& sarsR);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;

     virtual void accept(taxCollector& TC)=0;
    virtual void payTax()=0;

    
};

#endif