#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityFlyweight.h"

/**
 * @brief Represents a Power Plant in the utility system.
 * 
 * The PowerPlant class inherits from UtilityFlyweight and represents a power 
 * generation facility with characteristics such as cost, capacity, 
 * operational status, and the resources it consumes.
 */
class PowerPlant : public UtilityFlyweight {
public:
    /**
     * @brief Default constructor for PowerPlant.
     * 
     * Initializes a PowerPlant instance with default values representing 
     * typical characteristics of a power plant.
     */
    PowerPlant();

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
    PowerPlant(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);

    /**
     * @brief Connects the power plant and checks its operational status.
     * 
     * If the power plant is operational and the distance is within the effect radius,
     * it indicates that the power plant is providing power. Otherwise, it notifies that
     * the connection is out of range.
     * 
     * @param distance The distance to check against the effect radius.
     */
    void connect(double distance);

    /**
     * @brief Clones the PowerPlant instance.
     * 
     * Creates a shared pointer to a new instance of PowerPlant with the same properties.
     * 
     * @return A shared pointer to the cloned PowerPlant instance.
     */
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif
