//ABSTRACT PRODUCT/PROTORYPE
#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H
#include <memory>
#include <string>
#include <iostream>

#include "CityComponent.h"
class PublicService : public CityComponent{
private:
  bool water;
  bool electricity;
  bool sewage;
  bool wasteManagement;
  std::string status;

public:
    PublicService(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    virtual ~PublicService() = default;
    virtual void provideService() = 0;
    virtual void checkUtilityStatus();
    virtual std::unique_ptr<PublicService> clone() const = 0; // Pure virtual function for polymorphism
    std::string getBuildingType() override{
      return "Public Service";
    }


};

#endif