#include "FireStation.h"
#include <iostream>

/**
 * @brief Parameterized constructor for FireStation.
 * 
 * Initializes a FireStation object with the specified utilities and building status.
 * 
 * @param water Shared pointer to the water utility.
 * @param electricity Shared pointer to the electricity utility.
 * @param wasteManagement Shared pointer to the waste management utility.
 * @param sewage Shared pointer to the sewage utility.
 * @param buildingStatus The operational status of the fire station.
 */
FireStation::FireStation(std::shared_ptr<UtilityFlyweight> water, 
                         std::shared_ptr<UtilityFlyweight> electricity,
                         std::shared_ptr<UtilityFlyweight> wasteManagement, 
                         std::shared_ptr<UtilityFlyweight> sewage,
                         std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}

/**
 * @brief Provides fire extinguishing services.
 * 
 * This method simulates the fire station providing services 
 * to citizens in need of fire assistance.
 */
void FireStation::provideService(){
    std::cout << "Providing fire extinguishing services to citizens in need." << std::endl;
}

/**
 * @brief Clones the current FireStation object.
 * 
 * @return A unique pointer to a new FireStation object that is a copy of this one.
 */
std::unique_ptr<PublicService> FireStation::clone() const {
    return std::make_unique<FireStation>(*this);
}

/**
 * @brief Gets the display symbol for the fire station.
 * 
 * @return The character symbol representing the fire station, which is 'F'.
 */
char FireStation::getDisplaySymbol() const {
    return 'F'; // Character symbol for Fire Station
}

/**
 * @brief Displays the current status of the fire station.
 * 
 * Outputs information regarding the connectivity of utilities 
 * and the overall operational status of the fire station.
 */
void FireStation::displayStatus() {
    std::cout << "Status of Fire Station:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}
