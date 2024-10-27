#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "../CityComponent.h"
#include "../Utility/UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>

class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;
    std::string condition;      // Describes building condition, e.g., "Worn Out" or "Good"
    double price;
    double maintenanceCost;
    bool taxPaid;

    // Utility connections
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;

public:
    ResidentialBuilding(const std::string& condition, int bedrooms, double price, double maintenanceCost,
                        std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    virtual ~ResidentialBuilding() = default;
	void displayStatus();
	double getTaxRevenue();
    void connectWater(std::shared_ptr<UtilityFlyweight> water);
    void connectPower(std::shared_ptr<UtilityFlyweight> power);
    void connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste);
    void connectSewage(std::shared_ptr<UtilityFlyweight> sewage);
    void applyUtilityConsumption();
    void repairBuilding();
    virtual std::unique_ptr<ResidentialBuilding> clone() const = 0;
};

#endif