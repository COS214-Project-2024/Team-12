#include <iostream>
#include <string>
#include "Roads.h"

/**
 * @brief Clones the current Roads object, creating a new instance with the same properties.
 * @return std::unique_ptr<Transport> A unique pointer to the cloned Roads object.
 */
std::unique_ptr<Transport> Roads::clone() const {
    return std::make_unique<Roads>(*this);
}

/**
 * @brief Retrieves the capacity of the road.
 * @return double The traffic capacity of the road.
 */
double Roads::getCapacity() const {
    return 200;
}

/**
 * @brief Retrieves the construction cost of the road.
 * @return double The construction cost of the road.
 */
double Roads::getCost() const {
    return 800;
}

/**
 * @brief Retrieves the maintenance cost of the road.
 * @return double The maintenance cost of the road.
 */
double Roads::getMaintainanceCost() const {
    return 10;
}

/**
 * @brief Retrieves the speed limit of the road.
 * @return double The speed limit on the road.
 */
double Roads::getSpeed() const {
    return 60;
}

/**
 * @brief Retrieves the type of this transport as a string.
 * @return std::string The string "Road" representing this transport type.
 */
std::string Roads::getType() const {
    return "Road";
}
