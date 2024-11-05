#include "PowerPlant.h"

/**
 * @brief Default constructor for PowerPlant.
 * 
 * Initializes a PowerPlant instance with default values representing
 * a typical power plant's characteristics such as name, cost, capacity,
 * coverage radius, operational status, level, consumption rate, and required resources.
 */
PowerPlant::PowerPlant() : UtilityFlyweight(
    "Power Plant",     // name
    200.0,            // cost - highest cost due to importance
    100,              // capacity - highest capacity
    4.0,              // radius - largest coverage
    true,             // operational
    1,                // level
    15,               // consumption - high resource usage
    {{"Steel", 60}, {"Copper", 40}, {"Coal", 30}}  // more complex resources
){}

/**
 * @brief Parameterized constructor for PowerPlant.
 * 
 * Initializes a PowerPlant instance with specified values.
 * 
 * @param n The name of the power plant.
 * @param c The cost of the power plant.
 * @param cap The capacity of the power plant.
 * @param radius The coverage radius of the power plant.
 * @param operational Indicates if the power plant is operational.
 * @param l The level of the power plant.
 * @param consumption The resource consumption rate of the power plant.
 * @param resources A map of required resources and their quantities.
 */
PowerPlant::PowerPlant(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

/**
 * @brief Connects the power plant and checks its operational status within a given distance.
 * 
 * If the power plant is operational and the distance is within the effect radius,
 * it indicates that the power plant is providing power. Otherwise, it notifies that
 * the connection is out of range.
 * 
 * @param distance The distance to check against the effect radius.
 */
void PowerPlant::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name <<" providing power within range.\n";
    } else {
        std::cout << "Out of range of the PowerPlant.\n";
    }
}

/**
 * @brief Clones the PowerPlant instance.
 * 
 * Creates a shared pointer to a new instance of PowerPlant with the same properties.
 * 
 * @return A shared pointer to the cloned PowerPlant instance.
 */
std::shared_ptr<UtilityFlyweight> PowerPlant::clone() const {
    return std::make_shared<PowerPlant>(*this);
}
