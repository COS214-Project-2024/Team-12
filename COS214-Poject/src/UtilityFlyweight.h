#ifndef UTILITY_FLYWEIGHT_H
#define UTILITY_FLYWEIGHT_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <map>
#include <memory>

class taxCollector;

/**
 * @brief Abstract base class for utility components, providing shared functionality.
 * 
 * The UtilityFlyweight class defines shared attributes and methods for various utility types.
 * Implements the Prototype pattern for cloning and defines core utility attributes like cost, 
 * capacity, operational status, and resource requirements.
 */
class UtilityFlyweight : public CityComponent {
public:
    /**
     * @brief Default constructor for UtilityFlyweight.
     */
    UtilityFlyweight() = default;

    /**
     * @brief Parameterized constructor for UtilityFlyweight.
     * 
     * Allows setting initial values for key attributes of the utility.
     * 
     * @param n Name of the utility.
     * @param c Cost of the utility.
     * @param cap Capacity of the utility.
     * @param radius Effect radius of the utility.
     * @param operational Operational status of the utility.
     * @param l Level of the utility.
     * @param consumption Resource consumption rate of the utility.
     * @param resources Map of resources required for construction.
     */
    UtilityFlyweight(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);

    /**
     * @brief Connect the utility to a component within a specific distance.
     * 
     * Pure virtual function for establishing a connection based on distance. Must be implemented
     * in derived classes.
     * 
     * @param distance Distance to the component being connected.
     */
    virtual void connect(double distance) = 0;

    /**
     * @brief Virtual destructor for UtilityFlyweight.
     */
    virtual ~UtilityFlyweight() = default;

    /**
     * @brief Creates a clone of the utility, implementing the Prototype pattern.
     * 
     * Pure virtual method to be implemented by derived classes for cloning.
     * 
     * @return A shared pointer to the cloned UtilityFlyweight instance.
     */
    virtual std::shared_ptr<UtilityFlyweight> clone() const = 0;

    // Accessor methods
    std::string getName() const;                     ///< Getter for the utility's name.
    bool getOperationalStatus() const;               ///< Getter for the operational status.
    double getCost() const;                          ///< Getter for the monetary cost.
    double getEffectRadius() const;                  ///< Getter for the area of effect radius.
    int getCapacity() const;                         ///< Getter for the maximum capacity.
    int getLevel() const;                            ///< Getter for the utility's current level.
    virtual int getResourceConsumption() const;      ///< Getter for the resource consumption rate.
    std::map<std::string, int> getResourceNeeds() const; ///< Getter for resource requirements map.

    // Game logic methods
    /**
     * @brief Activates the utility, setting it to operational.
     */
    void activate();

    /**
     * @brief Deactivates the utility, setting it to non-operational.
     */
    void deactivate();

    /**
     * @brief Displays the current status of the utility.
     */
    void displayStatus();

    /**
     * @brief Gets the effect radius of the utility.
     * 
     * @return The effect radius.
     */
    double getRadius() const;

    /**
     * @brief Gets the type of the building, overridden from CityComponent.
     * 
     * @return The building type, which is "Utility" for UtilityFlyweight.
     */
    std::string getBuildingType() const override {
        return "Utility";
    }

    /**
     * @brief Accepts a taxCollector visitor, allowing it to interact with the utility.
     * 
     * Currently, this function does not perform any operations.
     * 
     * @param TC Pointer to the taxCollector visitor.
     */
    void accept(taxCollector*) override {
        // Currently no operations are performed here.
    }

    /**
     * @brief Increments the utility's level, typically for upgrades.
     */
    void incrementLevel() { level++; }

protected:
    /**
     * @brief Sets the resource consumption rate.
     * 
     * @param consumption The new resource consumption rate.
     */
    void setResourceConsumption(int consumption);

    std::string name;                               ///< Name of the utility.
    double cost = 0.0;                              ///< Monetary cost to build or upgrade.
    int capacity = 0;                               ///< Maximum number of buildings it can support.
    double effectRadius = 0.0;                      ///< Area of effect for the utility.
    bool isOperational = false;                     ///< Operational status of the utility.
    int level = 0;                                  ///< Level of the utility, upgradeable.
    int resourceConsumption = 0;                    ///< Resources required to keep the utility running.
    std::map<std::string, int> resourceNeeds;       ///< Map of resources required for construction.
};

#endif
