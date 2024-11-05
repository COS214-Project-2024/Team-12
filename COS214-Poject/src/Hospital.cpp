#include "Hospital.h"
#include <iostream>

/**
 * @brief Constructs a Hospital object with specified utilities and status.
 * 
 * @param water A shared pointer to the water utility.
 * @param electricity A shared pointer to the electricity utility.
 * @param wasteManagement A shared pointer to the waste management utility.
 * @param sewage A shared pointer to the sewage utility.
 * @param buildingStatus The status of the hospital.
 */
Hospital::Hospital(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                   std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                   std::string buildingStatus)
    : PublicService(water, electricity, wasteManagement, sewage) {
    status = buildingStatus;
}

/**
 * @brief Clones the current Hospital object.
 * 
 * @return A unique pointer to a cloned Hospital object.
 */
std::unique_ptr<PublicService> Hospital::clone() const {
    return std::make_unique<Hospital>(*this);
}

/**
 * @brief Displays the current status of the hospital, including utility connections.
 */
void Hospital::displayStatus() {
    std::cout << "Status of Hospital:\n";
    std::cout << " - Water: " << (waterSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Electricity: " << (powerSupply ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Waste Management: " << (wasteManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << " - Sewage: " << (sewageManagement ? "Connected" : "Not Connected") << "\n";
    std::cout << "Overall Status: " << status << "\n";
}

/**
 * @brief Gets the display symbol for the hospital.
 * 
 * @return The character symbol representing the hospital.
 */
char Hospital::getDisplaySymbol() const {
    return 'H'; // Character symbol for Hospital
}

/**
 * @brief Gets the building type of the hospital.
 * 
 * @return A string representing the building type.
 */
std::string Hospital::getBuildingType() const {
    return "Hospital";
}
