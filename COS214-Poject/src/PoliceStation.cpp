#include "PoliceStation.h"
#include <iostream>

PoliceStation::PoliceStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                             std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                             std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}



std::unique_ptr<PublicService> PoliceStation::clone() const {
    return std::make_unique<PoliceStation>(*this);

}

void PoliceStation::displayStatus() {
    std::cout << "Status of Police Station:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}



char PoliceStation::getDisplaySymbol() const {
    return 'P'; // Character symbol for Police Station
}
