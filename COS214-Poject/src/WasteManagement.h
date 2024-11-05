#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "UtilityFlyweight.h"

/**
 * @class WasteManagement
 * @brief Concrete class for managing waste utility in the city.
 * 
 * WasteManagement represents a specific utility that handles waste disposal and recycling operations. 
 * It can connect to components within a certain range and can be cloned to create new instances with the same attributes.
 */
class WasteManagement : public UtilityFlyweight {
public:
    /**
     * @brief Default constructor for WasteManagement, initializing with preset values.
     * 
     * Sets values for name, cost, capacity, effect radius, operational status, level, consumption, 
     * and required resources such as recycling and disposal equipment.
     */
    WasteManagement();

    /**
     * @brief Parameterized constructor for WasteManagement, allowing customization.
     * 
     * Allows specifying attributes such as the name, cost, capacity, effect radius, 
     * operational status, level, consumption rate, and required resources for the WasteManagement instance.
     * 
     * @param n The name of the waste management facility.
     * @param c The cost associated with waste management services.
     * @param cap The capacity of the waste management facility.
     * @param radius The effective radius within which waste management can operate.
     * @param operational The operational status of the waste management service.
     * @param l The level of the waste management service.
     * @param consumption The resource consumption rate of the waste management service.
     * @param resources A map of resources associated with the waste management facility.
     */
    WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);

    /**
     * @brief Connects the waste management service to a city component within a specified distance.
     * 
     * Outputs a message indicating if the connection is successful based on the operational status 
     * and the distance relative to the effect radius.
     * 
     * @param distance The distance to the component being connected to.
     */
    void connect(double distance);

    /**
     * @brief Clones the WasteManagement object, creating a new instance with the same attributes.
     * 
     * @return A shared pointer to the cloned WasteManagement object.
     */
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif
