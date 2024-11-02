#ifndef FIRESTATION_H
#define FIRESTAION_H

#include "PublicService.h"

class FireStation : public PublicService  {
private:
    bool water;
    bool electricity;
    bool sewage;
    bool wasteManagement;
    std::string status;
public:
    FireStation(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    ~FireStation();
    void provideService();
    std::unique_ptr<PublicService> clone() const;

};

#endif