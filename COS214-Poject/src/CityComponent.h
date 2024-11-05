#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

/**
 * @file CityComponent.h
 * @brief Abstract base class for components within the city simulation.
 * 
 * This file defines the CityComponent class, an abstract class for components in the city simulation,
 * providing common functionality such as observer management, location handling, and status display.
 */

class NPCObserver;
class taxCollector;

#include "Location.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

/**
 * @class CityComponent
 * @brief Abstract base class representing a component of a city.
 * 
 * This class defines an interface for city components, allowing for adding/removing subcomponents, 
 * managing NPC observers, setting locations, and displaying status. Derived classes represent
 * specific city components, such as buildings or utilities.
 */
class CityComponent {
public:
    /**
     * @brief Adds a subcomponent to the city component.
     * 
     * Allows derived classes to implement adding subcomponents, supporting composite structures.
     * 
     * @param component The city component to add as a subcomponent.
     */
    virtual void add(std::shared_ptr<CityComponent> component) {}

    /**
     * @brief Removes a subcomponent from the city component.
     * 
     * Allows derived classes to implement removal of subcomponents.
     * 
     * @param component The city component to remove.
     */
    virtual void remove(std::shared_ptr<CityComponent> component) {}

    /**
     * @brief Displays the status of the city component.
     * 
     * A pure virtual function that must be implemented by derived classes to show component-specific information.
     */
    virtual void displayStatus() = 0;

    /**
     * @brief Destructor for CityComponent.
     * 
     * Cleans up resources and observers when a CityComponent is destroyed.
     */
    virtual ~CityComponent();

    /**
     * @brief Adds an NPC observer to the component.
     */
    void addNpc();

    /**
     * @brief Removes an NPC observer from the component.
     */
    void removeNpc();

    /**
     * @brief Notifies all observers of changes in the city component.
     */
    void notify();

    /**
     * @brief Gets the type of building as a string.
     * 
     * A pure virtual function for retrieving the type of building represented by the component.
     * 
     * @return The type of building as a string.
     */
    virtual std::string getBuildingType() const = 0;

    /**
     * @brief Accepts a tax collector visitor.
     * 
     * Part of the Visitor pattern, allowing tax collectors to visit city components and
     * perform operations based on the component's type.
     * 
     * @param collector A pointer to a taxCollector object.
     */
    virtual void accept(taxCollector* collector) = 0;

    /**
     * @brief Sets the location of the component using x and y coordinates.
     * 
     * @param x The x-coordinate of the location.
     * @param y The y-coordinate of the location.
     */
    void setLocation(int x, int y);

    /**
     * @brief Sets the location of the component using a Location object.
     * 
     * @param loc A Location object representing the new location.
     */
    void setLocation(const Location& loc);

    /**
     * @brief Gets the current location of the component.
     * 
     * @return The current location as a Location object.
     */
    Location getLocation() const;

private:
    std::vector<NPCObserver*> observers;  /**< List of NPC observers observing this component */
    Location location;                    /**< Location of the city component */
};

#endif
