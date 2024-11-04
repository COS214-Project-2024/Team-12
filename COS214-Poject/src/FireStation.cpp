#include "FireStation.h"
#include<iostream>



FireStation::FireStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                         std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                         std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}

void FireStation::provideService(){
    std::cout << "Providing fire exstinguishing services to citizens in need." << std::endl;
}

std::unique_ptr<PublicService> FireStation::clone() const {
    return std::make_unique<FireStation>(*this);

}

char FireStation::getDisplaySymbol() const {
    return 'F'; // Character symbol for Fire Station
}

void FireStation::displayStatus() {
    std::cout << "Status of Fire Station:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}