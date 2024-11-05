#include "Park.h"

/**
 * @brief Constructs a Park object.
 * 
 * Initializes the Park with a specified type, capacity, price, and utility connections.
 * 
 * @param type The type of the park.
 * @param capacity The maximum visitor capacity of the park.
 * @param price The cost associated with the park.
 * @param water A shared pointer to the water utility.
 * @param power A shared pointer to the power utility.
 * @param waste A shared pointer to the waste management utility.
 * @param sewage A shared pointer to the sewage management utility.
 */
Park::Park(const std::string& type, int capacity, double price,
           std::shared_ptr<UtilityFlyweight> water, 
           std::shared_ptr<UtilityFlyweight> power,
           std::shared_ptr<UtilityFlyweight> waste, 
           std::shared_ptr<UtilityFlyweight> sewage)
    : LandMark(type, capacity, price, water, power, waste, sewage) {}

/**
 * @brief Destructor for the Park object.
 * 
 * Cleans up any resources held by the Park object.
 */
Park::~Park() {}

/**
 * @brief Displays the current status of the Park.
 * 
 * Outputs the name, capacity, price, and status of the park's utilities.
 */
void Park::displayStatus() {
    std::cout << "Park Status:\n";
    LandMark::displayStatus();
}

/**
 * @brief Creates a clone of the Park object.
 * 
 * @return A unique pointer to a new Park object that is a copy of this one.
 */
std::unique_ptr<LandMark> Park::clone() const {
    std::unique_ptr<Park> park = std::make_unique<Park>(
        landMarkType, visitorCapacity, price, 
        waterSupply, powerSupply, wasteManagement, sewageManagement
    );

    return park;
}

/**
 * @brief Retrieves the building type of the park.
 * 
 * @return A string representing the building type, which is "Park".
 */
std::string Park::getBuildingType() const {
    return "Park";
}
