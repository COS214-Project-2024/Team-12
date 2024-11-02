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
    std::string getBuildingType() const override{
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
    
    void setWaterSupply(std::shared_ptr<UtilityFlyweight> utility) { waterSupply = utility; }
    void setPowerSupply(std::shared_ptr<UtilityFlyweight> utility) { powerSupply = utility; }
    void setWasteManagement(std::shared_ptr<UtilityFlyweight> utility) { wasteManagement = utility; }
    void setSewageManagement(std::shared_ptr<UtilityFlyweight> utility) { sewageManagement = utility; }

    virtual std::string getDisplayColor() const {
        int coverage = getUtilityCoverage();
        std::cout << "Residential coverage: " << coverage << " for " << getBuildingType() << std::endl;
        if (coverage == 4) {
            return "\033[1;32m"; // Green for full
        } else if (coverage >= 2) {
            return "\033[1;33m"; // Yellow for partial
        } else {
            return "\033[1;31m"; // Red for insufficient
        }
    }
};

#endif