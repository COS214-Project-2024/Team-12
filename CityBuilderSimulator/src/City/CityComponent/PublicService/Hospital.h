#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "PublicService.h"

class Hospital : public PublicService  {
private:
    bool water;
    bool electricity;
    bool sewage;
    bool wasteManagement;//changed to bool
    std::string status;
public:
    Hospital(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    ~Hospital(){};
    void provideService();
    std::unique_ptr<PublicService> clone() const;

};

#endif