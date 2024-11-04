#include "PoliceStation.h"
#include <iostream>

/**
 * @class PoliceStation
 * @brief Represents a police station public service in the city.
 *
 * The PoliceStation class inherits from the PublicService class and includes utilities 
 * required for its operation, along with its status.
 */
PoliceStation::PoliceStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                             std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                             std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}

/**
 * @brief Creates a clone of the PoliceStation object.
 * 
 * @return A unique pointer to the cloned PoliceStation object.
 */
std::unique_ptr<PublicService> PoliceStation::clone() const {
    return std::make_unique<PoliceStation>(*this);
}

/**
 * @brief Displays the current status of the Police Station.
 * 
 * This includes the connection status of water, electricity, waste management, 
 * sewage, and the overall operational status of the police station.
 */
void PoliceStation::displayStatus() {
    std::cout << "Status of Police Station:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}

/**
 * @brief Retrieves the display symbol for the Police Station.
 * 
 * @return The character symbol representing the Police Station ('P').
 */
char PoliceStation::getDisplaySymbol() const {
    return 'P'; // Character symbol for Police Station
}
