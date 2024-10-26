#ifndef RESIDENTIAL_ZONE_COMPOSITE_H
#define RESIDENTIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>


class ResidentialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> buildings;
    double residentialTaxRate;

public:
    ResidentialZoneComposite(double taxRate);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;

    double getTaxRevenue() override;
    
};

#endif