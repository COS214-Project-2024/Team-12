#include "Hospital.h"
#include <iostream>

Hospital::Hospital(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                   std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                   std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}

std::unique_ptr<PublicService> Hospital::clone() const {
    return std::make_unique<Hospital>(*this);

}



void Hospital::displayStatus() {
    std::cout << "Status of Hospital:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}

char Hospital::getDisplaySymbol() const {
    return 'H'; // Character symbol for Hospital
}
