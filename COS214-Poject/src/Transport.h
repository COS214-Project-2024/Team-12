// ABSTRACT PRODUCT/PROTOTYPE
#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <memory>
#include <string>
#include "CityComponent.h"

/**
 * @brief Abstract class representing a generic transport.
 * 
 * The Transport class defines a prototype for various types of transportation.
 * Derived classes must implement the specific transportation details, such as
 * cost, maintenance cost, speed, capacity, and type. The class also provides a 
 * clone method to support creating copies of transport objects.
 */
class Transport {
public:
    /**
     * @brief Get the cost of the transport.
     * 
     * Pure virtual function to retrieve the cost associated with the transport.
     * 
     * @return The cost of the transport.
     */
    virtual double getCost() const = 0;

    /**
     * @brief Get the maintenance cost of the transport.
     * 
     * Pure virtual function to retrieve the ongoing maintenance cost.
     * 
     * @return The maintenance cost of the transport.
     */
    virtual double getMaintainanceCost() const = 0;

    /**
     * @brief Get the speed of the transport.
     * 
     * Pure virtual function to retrieve the speed.
     * 
     * @return The speed of the transport.
     */
    virtual double getSpeed() const = 0;

    /**
     * @brief Get the capacity of the transport.
     * 
     * Pure virtual function to retrieve the capacity for transportation.
     * 
     * @return The capacity of the transport.
     */
    virtual double getCapacity() const = 0;

    /**
     * @brief Get the type of transport.
     * 
     * Pure virtual function to retrieve the type of transport as a string.
     * 
     * @return The type of transport.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Clone the transport object.
     * 
     * Virtual function using the Prototype pattern to create a copy of the
     * transport object. Derived classes should implement specific cloning logic.
     * 
     * @return A unique pointer to the cloned transport object.
     */
    virtual std::unique_ptr<Transport> clone() const = 0;

    /**
     * @brief Virtual destructor for the Transport class.
     * 
     * Ensures proper cleanup of derived transport instances when deleted
     * through a pointer to the base class.
     */
    virtual ~Transport() = default;
};

#endif
