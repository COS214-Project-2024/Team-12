#include "UtilityFlyweight.h"

/**
 * @brief Constructs a UtilityFlyweight with specified attributes.
 * 
 * @param n Name of the utility.
 * @param c Cost of the utility.
 * @param cap Capacity of the utility.
 * @param radius Effect radius of the utility.
 * @param operational Operational status of the utility.
 * @param t Level of the utility.
 * @param consumption Resource consumption rate of the utility.
 * @param resources Map of resources required for construction.
 */
UtilityFlyweight::UtilityFlyweight(const std::string& n, double c, int cap, double radius, bool operational, int t, int consumption, const std::map<std::string, int>& resources)
        : name(n), cost(c), capacity(cap), effectRadius(radius), isOperational(operational), level(t), resourceConsumption(consumption), resourceNeeds(resources) {}

/**
 * @brief Retrieves the operational status of the utility.
 * 
 * @return True if operational, false otherwise.
 */
bool UtilityFlyweight::getOperationalStatus() const { return isOperational; }

/**
 * @brief Retrieves the monetary cost of the utility.
 * 
 * @return The cost of the utility.
 */
double UtilityFlyweight::getCost() const { return cost; }

/**
 * @brief Retrieves the capacity of the utility.
 * 
 * @return The maximum number of buildings the utility can support.
 */
int UtilityFlyweight::getCapacity() const { return capacity; }

/**
 * @brief Retrieves the effect radius of the utility.
 * 
 * @return The area of effect radius.
 */
double UtilityFlyweight::getEffectRadius() const { return effectRadius; }

/**
 * @brief Retrieves the level of the utility.
 * 
 * @return The current level of the utility.
 */
int UtilityFlyweight::getLevel() const { return level; }

/**
 * @brief Retrieves the resource consumption rate.
 * 
 * @return The rate of resource consumption per cycle.
 */
int UtilityFlyweight::getResourceConsumption() const { return resourceConsumption; }

/**
 * @brief Retrieves the map of resources required for construction.
 * 
 * @return A map of resources and quantities needed for construction.
 */
std::map<std::string, int> UtilityFlyweight::getResourceNeeds() const { return resourceNeeds; }

/**
 * @brief Retrieves the name of the utility.
 * 
 * @return The name of the utility.
 */
std::string UtilityFlyweight::getName() const { return name; }

/**
 * @brief Activates the utility, making it operational.
 */
void UtilityFlyweight::activate() {
    if (!isOperational) {
        isOperational = true;
        std::cout << name << " is now operational.\n";
    }
}

/**
 * @brief Deactivates the utility, making it non-operational.
 */
void UtilityFlyweight::deactivate() {
    if (isOperational) {
        isOperational = false;
        std::cout << name << " is now inactive.\n";
    }
}

/**
 * @brief Displays the current status of the utility, including attributes and requirements.
 */
void UtilityFlyweight::displayStatus() {
    std::cout << "Utility: " << name << "\n"
              << "Status: " << (isOperational ? "Operational" : "Inactive") << "\n"
              << "Level: " << level << "\n"
              << "Capacity: " << capacity << " buildings\n"
              << "Effect Radius: " << effectRadius << " units\n"
              << "Cost to Build: $" << cost << "\n"
              << "Resource Consumption per Cycle: " << resourceConsumption << "\n"
              << "Resources Needed for Construction: ";
    for (const auto& resource : resourceNeeds) {
        std::cout << resource.first << ": " << resource.second << " ";
    }
    std::cout << "\n";
}

/**
 * @brief Sets the resource consumption rate.
 * 
 * @param consumption The new resource consumption rate.
 */
void UtilityFlyweight::setResourceConsumption(int consumption) {
    resourceConsumption = consumption;
}

/**
 * @brief Retrieves the radius of effect.
 * 
 * @return The effect radius of the utility.
 */
double UtilityFlyweight::getRadius() const {
    return effectRadius;
}
