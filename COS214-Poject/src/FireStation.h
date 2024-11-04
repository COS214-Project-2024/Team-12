#ifndef FIRESTATION_H
#define FIRESTAION_H

#include "PublicService.h"

class FireStation : public PublicService  {
private:
    std::string status;
public:
   FireStation() = default;
   FireStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage, 
                std::string buildingStatus);
    ~FireStation() = default;
    void provideService() override;
    std::unique_ptr<PublicService> clone() const;
    char getDisplaySymbol() const override;
    void displayStatus() override;


};

#endif