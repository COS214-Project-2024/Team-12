/**
 * @file CulturalCenter.cpp
 * @brief Implements the CulturalCenter class methods.
 */

#include "CulturalCenter.h"

/**
 * @brief Constructs a CulturalCenter with specified type, capacity, price, and utility connections.
 * 
 * @param type The type of cultural center.
 * @param capacity The seating or attendance capacity of the cultural center.
 * @param price The cost of constructing the cultural center.
 * @param water Shared pointer to a UtilityFlyweight object representing the water supply.
 * @param power Shared pointer to a UtilityFlyweight object representing the power supply.
 * @param waste Shared pointer to a UtilityFlyweight object representing the waste management system.
 * @param sewage Shared pointer to a UtilityFlyweight object representing the sewage management system.
 */
CulturalCenter::CulturalCenter(const std::string& type, int capacity, double price, 
                               std::shared_ptr<UtilityFlyweight> water, 
                               std::shared_ptr<UtilityFlyweight> power,
                               std::shared_ptr<UtilityFlyweight> waste, 
                               std::shared_ptr<UtilityFlyweight> sewage)
    : LandMark(type, capacity, price, water, power, waste, sewage) {}

/**
 * @brief Destructor for CulturalCenter.
 */
CulturalCenter::~CulturalCenter() {}

/**
 * @brief Displays the current status of the Cultural Center, including its type and utility connections.
 */
void CulturalCenter::displayStatus() {
    std::cout << "Cultural Center Status:\n";
    LandMark::displayStatus();
}

/**
 * @brief Creates a copy of the current CulturalCenter instance.
 * 
 * @return A unique pointer to a cloned CulturalCenter object.
 */
std::unique_ptr<LandMark> CulturalCenter::clone() const {
    std::unique_ptr<CulturalCenter> culturalCenter = std::make_unique<CulturalCenter>(
        landMarkType, visitorCapacity, price, waterSupply, powerSupply, wasteManagement, sewageManagement
    );

    return culturalCenter;
}

/**
 * @brief Gets the building type as a string.
 * 
 * @return A string indicating the building type ("Cultural Center").
 */
std::string CulturalCenter::getBuildingType() const {
    return "Cultural Center";
}
