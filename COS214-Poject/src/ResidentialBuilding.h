#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <memory>

// #include "UtilityFlyweight.h"
// #include "WaterSupply.h"
// #include "CityComposite.h"
// #include "taxCollector.h"

class UtilityFlyweight;
class Government;
class taxCollector;
class CityComposite;


class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;
    double price;
    bool taxPayed;
    Government* bank;
    double ResidentialTaxRate;
    

    // Utility connections
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;


public:
    ResidentialBuilding() = default;
    ResidentialBuilding(int bedrooms, double price,std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    virtual ~ResidentialBuilding() = default;
	void displayStatus();
    void connectWater(std::shared_ptr<UtilityFlyweight> water);
    void connectPower(std::shared_ptr<UtilityFlyweight> power);
    void connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste);
    void connectSewage(std::shared_ptr<UtilityFlyweight> sewage);
    void applyUtilityConsumption();
    virtual std::shared_ptr<ResidentialBuilding> clone() const = 0;

    virtual void accept(taxCollector* TC) = 0;
    
    virtual void payTax() = 0;
    std::string getBuildingType() override{
        return "Residential Building";
    }
};

#endif