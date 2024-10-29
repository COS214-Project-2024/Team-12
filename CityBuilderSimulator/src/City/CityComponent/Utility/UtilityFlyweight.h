#ifndef UTILITY_FLYWEIGHT_H
#define UTILITY_FLYWEIGHT_H

#include "../CityComponent.h"
#include <iostream>
#include <string>
#include <map>
#include <memory>

class UtilityFlyweight : public CityComponent {
public:
    UtilityFlyweight() = default;
    UtilityFlyweight(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    virtual void connect(double distance) = 0;
    virtual ~UtilityFlyweight() = default;

    // Prototype pattern: clone method for creating copies
    virtual std::unique_ptr<UtilityFlyweight> clone() const = 0;

    std::string getName() const;// Getter for name
    
    // Accessor methods
    bool getOperationalStatus() const;
    double getCost() const;
    double getEffectRadius() const;
    int getCapacity() const;
    int getLevel() const;
    int getResourceConsumption() const;
    std::map<std::string, int> getResourceNeeds() const;

    // Game logic methods
    void activate();
    void deactivate(); // If NPCs did not pay taxes ;)

    void displayStatus();

protected:
    std::string name;
    double cost = 0.0;                               // Monetary cost to build or upgrade
    int capacity = 0;                               // Max buildings it can support
    double effectRadius = 0.0;                        // Area of effect
    bool isOperational = false;                         // Track if the utility is working
    int level = 0;                                  // Utility's level; - can be upgraded with Decorator
    int resourceConsumption = 0;                    // Resources to keep the utility operating
    std::map<std::string, int> resourceNeeds;   // Resources required for construction
};

#endif