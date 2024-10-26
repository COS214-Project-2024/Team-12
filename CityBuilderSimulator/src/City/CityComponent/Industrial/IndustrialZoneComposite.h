#ifndef INSUSTRIAL_ZONE_COMPOSITE_H
#define INSUSTRIAL_ZONE_COMPOSITE_H

#include "../CityComponent.h"
#include <vector>


class IndustrialZoneComposite : public CityComponent {
private:
    std::vector<CityComponent*> industrialbuildings;
    double industrialTaxRate;

public:
    IndustrialZoneComposite(double taxRate);

    void add(CityComponent* building) override;

    void remove(CityComponent* building) override;

    void displayStatus() override;

    double getTaxRevenue() override;
    
};

#endif