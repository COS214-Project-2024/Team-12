#include "PoliceStation.h"
#include <iostream>

PoliceStation::PoliceStation(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) :PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}
void PoliceStation::provideService(){
    std::cout << "Here to protect and serve the citizens of this city." << std::endl;
}

std::unique_ptr<PublicService> PoliceStation::clone() const {
    return std::make_unique<PoliceStation>(*this);

}