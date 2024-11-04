#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "PublicService.h"

class PoliceStation : public PublicService  {
private:
    std::string status;
public:
    PoliceStation() = default;
     PoliceStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                  std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                  std::string buildingStatus);
    ~PoliceStation() =default;
   void provideService() override{
    std::cout << "Police Station is ensuring public safety.\n";
}
    std::unique_ptr<PublicService> clone() const;
    void displayStatus() override;
  
    char getDisplaySymbol() const override;


};

#endif