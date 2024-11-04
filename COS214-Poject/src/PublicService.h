//ABSTRACT PRODUCT/PROTORYPE
#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <memory>

class UtilityFlyweight;
class Government;
class taxCollector;
class CityComposite;
class PublicService : public CityComponent{
protected:
  std::shared_ptr<UtilityFlyweight> waterSupply;
  std::shared_ptr<UtilityFlyweight> powerSupply;
  std::shared_ptr<UtilityFlyweight> wasteManagement;
  std::shared_ptr<UtilityFlyweight> sewageManagement;
public:
    PublicService() = default;
    PublicService(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    virtual void provideService() = 0;
   virtual ~PublicService() = default;
      // Display methods
    virtual void displayStatus() = 0;
    std::string getBuildingType() const override{
      return "Public Service";
    }
    virtual char getDisplaySymbol() const = 0; // For map display

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

    void accept(taxCollector* TC) override {}

};

#endif