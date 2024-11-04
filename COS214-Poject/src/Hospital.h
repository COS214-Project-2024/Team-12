#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "PublicService.h"
#include "taxCollector.h"

class Hospital : public PublicService  {
private:
    bool water;
    bool electricity;
    bool sewage;
    bool wasteManagement;
    std::string status;
public:
 Hospital(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
             std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
             std::string buildingStatus);
    ~Hospital() = default;
    void provideService() override{
    std::cout << "Hospital is providing medical services.\n";
}
    std::unique_ptr<PublicService> clone() const;
    void displayStatus() override;
    char getDisplaySymbol() const override;
    std::string getBuildingType() const;

};

#endif