#include "PoliceStation.h"
#include <iostream>

PoliceStation::PoliceStation(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) :PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}

PoliceStation::PoliceStation() : PoliceStation(false, false, false, false, "Not Operational") {
    // Default constructor with default values
}


void PoliceStation::provideService(){
    std::cout << "Here to protect and serve the citizens of this city." << std::endl;
}

std::unique_ptr<PublicService> PoliceStation::clone() const {
    return std::make_unique<PoliceStation>(*this);

}

void PoliceStation::displayStatus() {
    // Implement the specific display logic for PoliceStation
    std::cout << "Displaying status of the Police Station" << std::endl;
}

void PoliceStation::accept(taxCollector*) {
    // Implement the behavior of accept for tax collection
    std::cout << "Police Station accepts tax collection" << std::endl;
    // Additional logic as needed
}