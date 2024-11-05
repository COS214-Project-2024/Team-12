#include "Monument.h"

/**
 * @brief Constructs a Monument object with specified type, capacity, price, and utility connections.
 * 
 * @param type The type of the monument.
 * @param capacity The visitor capacity of the monument.
 * @param price The price or cost associated with the monument.
 * @param water Shared pointer to water utility flyweight.
 * @param power Shared pointer to power utility flyweight.
 * @param waste Shared pointer to waste management utility flyweight.
 * @param sewage Shared pointer to sewage management utility flyweight.
 */
Monument::Monument(const std::string& type, int capacity, double price, 
                   std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
                   std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type, capacity, price, water, power, waste, sewage) {}

/**
 * @brief Destructor for Monument.
 */
Monument::~Monument(){}

/**
 * @brief Displays the status of the monument, including its type, capacity, price, and connected utilities.
 */
void Monument::displayStatus() {
    std::cout << "Monument Status:\n";
    LandMark::displayStatus();
}

/**
 * @brief Creates a clone of the Monument object.
 * 
 * This method returns a unique pointer to a new Monument object with the same properties as the current one.
 * 
 * @return A unique pointer to a cloned Monument object.
 */
std::unique_ptr<LandMark> Monument::clone() const {
    std::unique_ptr<Monument> monument = std::make_unique<Monument>(
        landMarkType, visitorCapacity, price, waterSupply, powerSupply, wasteManagement, sewageManagement
    );
    return monument;
}

/**
 * @brief Gets the building type of the monument.
 * 
 * @return A string representing the building type, which is "Monument" for this class.
 */
std::string Monument::getBuildingType() const {
    return "Monument";
}
