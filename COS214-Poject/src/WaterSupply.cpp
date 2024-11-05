#include "WaterSupply.h"

/**
 * @brief Default constructor for WaterSupply, initializing it with preset values.
 * 
 * Sets moderate values for cost, capacity, radius, operational status, level, consumption,
 * and required resources such as Steel and Plastic.
 */
WaterSupply::WaterSupply() : UtilityFlyweight(
    "Water Supply",    // name
    150.0,             // cost - moderate cost
    60,                // capacity - can serve many buildings
    3.0,               // radius - moderate coverage
    true,              // operational
    1,                 // level
    10,                // consumption - moderate resource usage
    {{"Steel", 40}, {"Plastic", 20}}  // basic resources needed
) {}

/**
 * @brief Parameterized constructor for WaterSupply with customizable attributes.
 * 
 * Allows specifying the name, cost, capacity, effect radius, operational status,
 * level, consumption rate, and required resources for the WaterSupply instance.
 * 
 * @param n The name of the water supply.
 * @param c The cost associated with the water supply.
 * @param cap The capacity of the water supply.
 * @param radius The effective radius within which the water supply can operate.
 * @param operational The operational status of the water supply.
 * @param l The level of the water supply.
 * @param consumption The consumption rate of the water supply.
 * @param resources A map of resources associated with the water supply.
 */
WaterSupply::WaterSupply(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

/**
 * @brief Connects the water supply to a city component within a specified distance.
 * 
 * Outputs a message indicating if the connection is successful based on the
 * operational status and the distance relative to the effect radius.
 * 
 * @param distance The distance to the component being connected to.
 */
void WaterSupply::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " providing water within range.\n";
    } else {
        std::cout << "Out of range of the WaterSupply.\n";
    }
}

/**
 * @brief Clones the WaterSupply object, creating a new instance with the same attributes.
 * 
 * @return A shared pointer to the cloned WaterSupply object.
 */
std::shared_ptr<UtilityFlyweight> WaterSupply::clone() const {
    return std::make_shared<WaterSupply>(*this);
}
