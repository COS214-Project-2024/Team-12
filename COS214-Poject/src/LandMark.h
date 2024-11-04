#ifndef LANDMARK_H
#define LANDMARK_H

#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>


class LandMark : public CityComponent {
protected:
    std::string landMarkType;
    int visitorCapacity;
    double price;

    // Utility connections for area-of-effect functionality
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;


public:
    LandMark(const std::string& type, int  capacity, double price,std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
	virtual void displayStatus() override;
    double getPrice() const {return price;}
    
    // Utility-related methods
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

    std::string getBuildingType() const override{
        return "LandMark";
    }

    //virtual char getDisplaySymbol() const = 0; // For map display

    void accept(taxCollector* TC) {}
};

#endif