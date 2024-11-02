#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <memory>

class UtilityFlyweight;
class Government;
class taxCollector;
class CityComposite;

class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;
    double price;
    bool taxPaid;
    
    // Utility connections for area-of-effect functionality
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;


public:
    ResidentialBuilding(int bedrooms, double cost,std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    
    // Tax related methods
    void setTaxPaid(bool paid);
    bool isTaxPaid() const;
    void accept(taxCollector* TC) override;
    double getPrice() const {return price;}
    
    // Display methods
    void displayStatus() override;
    std::string getBuildingType() override{
        return "Residential Building";
    }
    virtual char getDisplaySymbol() const = 0; // For map display

    // Utility-related methods - For NPC Mananger Singleton
    int getUtilityCoverage() const {
        int coverage = 0;
        if (waterSupply) coverage++;
        if (powerSupply) coverage++;
        if (wasteManagement) coverage++;
        if (sewageManagement) coverage++;
        return coverage;
    }
    bool hasUtilities() const {
        return waterSupply && powerSupply && 
            wasteManagement && sewageManagement;
    }
};

#endif