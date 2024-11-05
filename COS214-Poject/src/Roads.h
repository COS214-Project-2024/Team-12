// CONCRETE PRODUCT/PROTOTYPE
#ifndef ROADS_H
#define ROADS_H

#include <iostream>
#include <string>
#include "Transport.h"

/**
 * @brief Enum representing different types of roads.
 */
enum class roadType {
    Highway,
    Street,
    Avenue,
    Boulevard,
    Alley,
    Roundabout,
    Bridge,
    Tunnel,
    PedestrianPath
};

/**
 * @brief A concrete implementation of Transport representing various types of roads.
 * 
 * The Roads class provides specific implementations for road-related attributes 
 * like traffic capacity and road type. It implements the Transport interface.
 */
class Roads : public Transport {
private:
    int trafficCapacity;  /**< Traffic capacity of the road. */
    roadType road;        /**< Type of the road, defined by roadType enum. */

public:
    /**
     * @brief Creates a clone of this Roads object.
     * @return std::unique_ptr<Transport> A unique pointer to a cloned Roads object.
     */
    std::unique_ptr<Transport> clone() const override;

    /**
     * @brief Gets the speed of the road.
     * @return double Speed value for the road.
     */
    double getSpeed() const override;

    /**
     * @brief Gets the construction cost of the road.
     * @return double Cost value for the road.
     */
    double getCost() const override;

    /**
     * @brief Gets the maintenance cost of the road.
     * @return double Maintenance cost for the road.
     */
    double getMaintainanceCost() const override;

    /**
     * @brief Gets the traffic capacity of the road.
     * @return double Capacity of the road.
     */
    double getCapacity() const override;

    /**
     * @brief Gets the type of road as a string.
     * @return std::string Road type description.
     */
    std::string getType() const override;

    /**
     * @brief Default constructor for Roads.
     */
    Roads() {
        // Constructor body (can be empty)
    }

    /**
     * @brief Destructor for Roads.
     */
    ~Roads() {
        // Destructor body (can be empty)
    }
};

#endif
