#include "FireStation.h"
#include<iostream>


FireStation::FireStation(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) :PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}
void FireStation::provideService(){
    std::cout << "Providing fire exstinguishing services to citizens in need." << std::endl;
}

std::unique_ptr<PublicService> FireStation::clone() const {
    return std::make_unique<FireStation>(*this);

}