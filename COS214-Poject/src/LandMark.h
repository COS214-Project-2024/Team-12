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

    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;


public:
    LandMark(const std::string& type, int  capacity, double price,std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
            std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    virtual ~LandMark() = default;
	virtual void displayStatus();
    void connectWater(std::shared_ptr<UtilityFlyweight> water);
    void connectPower(std::shared_ptr<UtilityFlyweight> power);
    void connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste);
    void connectSewage(std::shared_ptr<UtilityFlyweight> sewage);
    void applyUtilityConsumption();
    virtual std::unique_ptr<LandMark> clone() const = 0;
    std::string getBuildingType() override{
        return "LandMark";
    }
};

#endif