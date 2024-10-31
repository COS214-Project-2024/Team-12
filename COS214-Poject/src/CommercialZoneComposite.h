#ifndef COMMERCIAL_ZONE_COMPOSITE_H
#define COMMERCIAL_ZONE_COMPOSITE_H

#include "CityComponent.h"
#include <vector>


class CommercialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> commercialbuildings;
    double commercialTaxRate;

public:
    CommercialZoneComposite(double taxRate);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;

    //cant implement Composite
    //void accept(taxCollector* TC)override{} ;


    std::string getBuildingType() override{
        return "Commercialzone";
    }

    
    
};

#endif