#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "../CityComponent.h"
#include "../Utility/UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>
#include "WaterSupply.h"
#include "CityComposite.h"
#include "CollectTaxResidential.h"
#include "Government.h"
#include "GreenTechnologyDecorator.h"
#include <future>
#include <chrono>
#include <atomic>


class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;
    double price;
    bool taxPayed;
    std::atomic<bool> taxPayed;
    std::future<void> resetTax;
    double ResidentialTaxRate;
    

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
    bool hasGreenTechnology() const;
    virtual std::unique_ptr<ResidentialBuilding> clone() const = 0;
    virtual void accept(CollectTaxResidential& TC)=0;
    virtual void payTax()=0;
};

#endif