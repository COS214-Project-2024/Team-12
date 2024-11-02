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
    Hospital(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus);
    Hospital();
    ~Hospital(){};
    void provideService();
    std::unique_ptr<PublicService> clone() const;
    void displayStatus() override;
    void accept(taxCollector*) override;

};

#endif