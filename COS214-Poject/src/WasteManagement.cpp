#include "WasteManagement.h"

/**
 * @brief Default constructor for WasteManagement.
 * 
 * Initializes WasteManagement with default values such as name, cost, capacity,
 * radius, operational status, level, resource consumption, and required resources.
 */
WasteManagement::WasteManagement() : UtilityFlyweight(
    "Waste Management",  // name
    125.0,               // cost - lowest cost
    50,                  // capacity - moderate capacity
    2.0,                 // radius - smallest coverage
    true,                // operational
    1,                   // level
    5,                   // consumption - lowest resource usage
    {{"Steel", 20}, {"Plastic", 30}}  // required resources for construction
) {}

/**
 * @brief Parameterized constructor for WasteManagement.
 * 
 * @param n The name of the utility.
 * @param c The construction cost.
 * @param cap The capacity, i.e., the number of buildings it can support.
 * @param radius The effective radius of the utility.
 * @param operational The operational status of the utility.
 * @param l The level of the utility.
 * @param consumption The resource consumption per cycle.
 * @param resources The map of resources required for construction.
 */
WasteManagement::WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

/**
 * @brief Connects the WasteManagement utility to a building based on distance.
 * 
 * Outputs a message indicating if the utility is operational and within range
 * to provide waste management services to the target building.
 * 
 * @param distance The distance to the target building.
 */
void WasteManagement::connect(double distance){
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " collecting waste within range.\n";
    } else {
        std::cout << "Out of range of the WasteManagement.\n";
    }
}

/**
 * @brief Creates a clone of the WasteManagement utility.
 * 
 * Implements the Prototype pattern to return a new instance that is a copy of
 * the current WasteManagement object.
 * 
 * @return A shared pointer to the cloned WasteManagement instance.
 */
std::shared_ptr<UtilityFlyweight> WasteManagement::clone() const  {
    return std::make_shared<WasteManagement>(*this);
}
