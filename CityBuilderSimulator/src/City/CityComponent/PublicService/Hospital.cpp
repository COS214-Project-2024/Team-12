#include "Hospital.h"
#include <iostream>

Hospital::Hospital(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) :PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}
void Hospital::provideService(){
    std::cout << "Providing health care to all citizens in need." << std::endl;
}

std::unique_ptr<PublicService> Hospital::clone() const {
    return std::make_unique<Hospital>(*this);

}