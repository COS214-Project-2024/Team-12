#include "SewageSystem.h"

/**
 * @brief Default constructor for SewageSystem.
 * 
 * Initializes a SewageSystem instance with preset attributes:
 * - Name: "Sewage System"
 * - Cost: 175.0
 * - Capacity: 40 buildings
 * - Radius: 2.5 units
 * - Operational: true
 * - Level: 1
 * - Consumption: 8 resource units
 * - Resources: {"Steel": 30, "Plastic": 40, "Concrete": 20}
 */
SewageSystem::SewageSystem() : UtilityFlyweight(
    "Sewage System",   // name
    175.0,            // cost - moderately high
    40,               // capacity - lower capacity
    2.5,              // radius - smaller coverage
    true,             // operational
    1,                // level
    8,                // consumption - lower resource usage
    {{"Steel", 30}, {"Plastic", 40}, {"Concrete", 20}}  // varied resources
) {}

/**
 * @brief Parameterized constructor for SewageSystem.
 * 
 * Initializes a SewageSystem instance with specified attributes.
 * 
 * @param n Name of the sewage system.
 * @param c Cost of the sewage system.
 * @param cap Capacity of the sewage system to serve buildings.
 * @param radius Coverage radius of the sewage system.
 * @param operational Initial operational status.
 * @param l Level of the sewage system.
 * @param consumption Resources consumed per cycle.
 * @param resources Map of resources required for construction.
 */
SewageSystem::SewageSystem(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

/**
 * @brief Connects the sewage system to a building within a specified distance.
 * 
 * If the building is within range, connects to it; otherwise, notifies that it is out of range.
 * 
 * @param distance Distance to the building attempting to connect.
 */
void SewageSystem::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " managing sewage within range.\n";
    } else {
        std::cout << "Out of range of the SewageSystem.\n";
    }
}

/**
 * @brief Clones the current SewageSystem instance.
 * 
 * Creates a copy of the SewageSystem instance, implementing the Prototype pattern.
 * 
 * @return std::shared_ptr<UtilityFlyweight> A shared pointer to the cloned SewageSystem instance.
 */
std::shared_ptr<UtilityFlyweight> SewageSystem::clone() const {
    return std::make_shared<SewageSystem>(*this);
}
