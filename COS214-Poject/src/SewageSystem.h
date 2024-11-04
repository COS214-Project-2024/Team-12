#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "UtilityFlyweight.h"

/**
 * @class SewageSystem
 * @brief A concrete UtilityFlyweight that represents a sewage management utility.
 * 
 * The SewageSystem class models a sewage utility, which provides sewage handling services
 * for buildings within a defined range. It offers specific functionality such as connecting
 * to nearby buildings and creating copies of itself.
 */
class SewageSystem : public UtilityFlyweight {
public:
    /**
     * @brief Default constructor for SewageSystem.
     * 
     * Initializes a SewageSystem instance with preset attributes, including cost,
     * capacity, and effect radius.
     */
    SewageSystem();

    /**
     * @brief Parameterized constructor for SewageSystem.
     * 
     * Initializes a SewageSystem instance with specified attributes, including name, cost,
     * capacity, effect radius, operational status, level, resource consumption, and required resources.
     * 
     * @param n Name of the sewage system.
     * @param c Cost to build the sewage system.
     * @param cap Capacity to serve buildings.
     * @param radius Coverage radius of the sewage system.
     * @param operational Operational status of the system.
     * @param l Level of the sewage system.
     * @param consumption Resources consumed per cycle.
     * @param resources Map of resources needed for construction.
     */
    SewageSystem(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);

    /**
     * @brief Connects the sewage system to a building within a certain distance.
     * 
     * Checks if the building is within range and, if so, connects to it, otherwise notifies that it is out of range.
     * 
     * @param distance Distance to the building attempting to connect.
     */
    void connect(double distance);

    /**
     * @brief Clones the SewageSystem instance.
     * 
     * Implements the Prototype pattern to create a copy of the current SewageSystem instance.
     * 
     * @return std::shared_ptr<UtilityFlyweight> Shared pointer to the cloned SewageSystem.
     */
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif // SEWAGE_SYSTEM_H
