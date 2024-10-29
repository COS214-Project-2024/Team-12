#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "../src/City/CityComponent/CityComponent.h"
#include "../src/City/CityComponent/Utility/UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>
#include "../src/City/CityComponent/Utility/WaterSupply.h"
#include "../src/City/CityComponent/CityComposite/CityComposite.h"
#include "../src/City/taxCollector.h"


class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;
    double price;
    bool taxPayed;
    CityComposite* city;


    // Utility connections
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;


public:
    ResidentialBuilding();
    ResidentialBuilding(int bedrooms, double price,std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    virtual ~ResidentialBuilding() = default;
	void displayStatus();
    void connectWater(std::shared_ptr<UtilityFlyweight> water);
    void connectPower(std::shared_ptr<UtilityFlyweight> power);
    void connectWasteManagement(std::shared_ptr<UtilityFlyweight> waste);
    void connectSewage(std::shared_ptr<UtilityFlyweight> sewage);
    void applyUtilityConsumption();
    virtual std::unique_ptr<ResidentialBuilding> clone() const = 0;
    virtual void accept(taxCollector* TC)=0;
    virtual void payTax()=0;
};

#endif