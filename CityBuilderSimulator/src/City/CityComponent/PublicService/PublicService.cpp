#include "PublicService.h"
#include <iostream>
//cpp file new
PublicService::PublicService(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus){
this->electricity = electricityStatus;
this->water = waterStatus;
this->wasteManagement = wasteManagementStatus;
this->sewage = sewageStatus;
this->status = buildingStatus;

}
