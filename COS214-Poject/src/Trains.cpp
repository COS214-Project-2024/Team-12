#include <iostream>
#include <string>
#include "Trains.h"

/**
 * @brief Creates a clone of the current Trains instance.
 * 
 * Implements the Prototype pattern to provide a new instance with the same properties
 * as the existing Trains instance.
 * 
 * @return std::unique_ptr<Transport> A unique pointer to the cloned Trains instance.
 */
std::unique_ptr<Transport> Trains::clone() const {
    return std::make_unique<Trains>(*this);
}

/**
 * @brief Gets the cargo capacity of the train.
 * 
 * @return double Capacity of the train in terms of cargo.
 */
double Trains::getCapacity() const {
    return 500;
}

/**
 * @brief Gets the cost associated with the train.
 * 
 * @return double Cost to acquire or build the train.
 */
double Trains::getCost() const {
    return 1000;
}

/**
 * @brief Gets the maintenance cost of the train.
 * 
 * @return double Ongoing maintenance cost of the train.
 */
double Trains::getMaintainanceCost() const {
    return 50;
}

/**
 * @brief Gets the speed of the train.
 * 
 * @return double Speed of the train.
 */
double Trains::getSpeed() const {
    return 100;
}

/**
 * @brief Gets the type of the transport.
 * 
 * @return std::string Type of transport, which is "Train".
 */
std::string Trains::getType() const {
    return "Train";
}
