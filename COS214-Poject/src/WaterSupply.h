#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityFlyweight.h"
#include <memory>
#include <map>
#include <string>

class CityComponent;

/**
 * @class WaterSupply
 * @brief Represents a water supply utility that can be connected to city components within a specific radius.
 */
class WaterSupply : public UtilityFlyweight {
public:
    /**
     * @brief Default constructor for WaterSupply.
     */
    WaterSupply();

    /**
     * @brief Constructs a WaterSupply object with specified attributes.
     * @param n The name of the water supply.
     * @param c The cost associated with the water supply.
     * @param cap The capacity of the water supply.
     * @param radius The effective radius within which the water supply can operate.
     * @param operational The operational status of the water supply.
     * @param l The water supply level.
     * @param consumption The consumption rate of the water supply.
     * @param resources A map of resources associated with the water supply.
     */
    WaterSupply(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);

    /**
     * @brief Connects the water supply to a city component within a specified distance.
     * @param distance The distance to the component being connected to.
     */
    void connect(double distance);

    /**
     * @brief Clones the WaterSupply object, creating a new instance with the same attributes.
     * @return A shared pointer to the cloned WaterSupply object.
     */
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif
