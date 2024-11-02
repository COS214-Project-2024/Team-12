#ifndef SCHOOL_H
#define SCHOOL_H

#include "PublicService.h"

class School : public PublicService  {
private:
    bool water;
    bool electricity;
    bool sewage;
    bool wasteManagement;
    std::string status;
public:
    School(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    ~School();
    void provideService();
    std::unique_ptr<PublicService> clone() const;

};

#endif