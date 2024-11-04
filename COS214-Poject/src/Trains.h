// CONCRETE PRODUCT/PROTOTYPE
#ifndef TRAINS_H
#define TRAINS_H

#include <memory>
#include <string>
#include "Transport.h"

/**
 * @class Trains
 * @brief A concrete implementation of the Transport class representing a train.
 * 
 * The Trains class encapsulates the properties and behaviors of a train transport,
 * including its capacity, speed, cost, and maintenance requirements.
 */
class Trains : public Transport {
private:
    int cargoCapacity;         ///< Capacity of the train for carrying cargo.
    double railwayLength;      ///< Total length of railway covered by the train.
    int numberOfStations;      ///< Number of stations the train stops at.

public:
    /**
     * @brief Creates a copy of the current Trains instance.
     * 
     * Implements the Prototype pattern, allowing for the creation of a new instance
     * with the same properties as the current one.
     * 
     * @return std::unique_ptr<Transport> A unique pointer to the cloned Trains instance.
     */
    std::unique_ptr<Transport> clone() const override;

    /**
     * @brief Retrieves the speed of the train.
     * 
     * @return double Speed of the train.
     */
    double getSpeed() const override;

    /**
     * @brief Retrieves the cost associated with the train.
     * 
     * @return double Cost of the train.
     */
    double getCost() const override;

    /**
     * @brief Retrieves the maintenance cost for the train.
     * 
     * @return double Maintenance cost of the train.
     */
    double getMaintainanceCost() const override;

    /**
     * @brief Retrieves the capacity of the train.
     * 
     * @return double Capacity of the train.
     */
    double getCapacity() const override;

    /**
     * @brief Returns the type of transport as a string.
     * 
     * @return std::string Type of transport, e.g., "Train".
     */
    std::string getType() const override;

    /**
     * @brief Default constructor for Trains.
     */
    Trains() {}

    /**
     * @brief Destructor for Trains.
     */
    ~Trains() {}
};

#endif
