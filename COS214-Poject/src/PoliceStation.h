#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "PublicService.h"

class PoliceStation : public PublicService  {
private:
    bool water;
    bool electricity;
    bool sewage;
    bool wasteManagement;
    std::string status;
public:
    PoliceStation();  // Default constructor
    PoliceStation(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    ~PoliceStation();
    void provideService();
    std::unique_ptr<PublicService> clone() const;
    void displayStatus() override;
    void accept(taxCollector* TC) override;

};

#endif