#ifndef CONSTRUCTIONRESOURCEPRODUCT_H
#define CONSTRUCTIONRESOURCEPRODUCT_H

#include <string>
#include <iostream>
#include "CityComponent.h"

using namespace std;

/**
 * @class ConstructionResourceProduct
 * @brief Represents a construction resource product in the city-building simulation.
 * 
 * This class models a resource used for construction, managing attributes like 
 * quantity, unit cost, and location, and providing methods for consumption, replenishment,
 * and status display.
 */
class ConstructionResourceProduct : public CityComponent {
private:
    int quantity;          /**< The quantity of the resource available */
    int unitCost;          /**< The cost per unit of the resource */
    string name;           /**< Name of the resource */
    bool readyForCollection; /**< Indicates if the resource is ready for collection */
    Location location;     /**< The location of the resource */

public:
    /**
     * @brief Constructs a ConstructionResourceProduct with specified name, quantity, and unit cost.
     * @param name The name of the resource.
     * @param quantity The initial quantity of the resource.
     * @param unitCost The cost per unit of the resource.
     */
    ConstructionResourceProduct(string name, int quantity, int unitCost);

    /**
     * @brief Destructor for ConstructionResourceProduct.
     */
    ~ConstructionResourceProduct();

    /**
     * @brief Consumes a specified amount of the resource.
     * @param amount The amount to consume.
     */
    void ConsumeResource(int amount);

    /**
     * @brief Displays the current status of the resource, including name, quantity, and total cost.
     */
    void displayStatus();

    /**
     * @brief Calculates and returns the total cost of the available resource.
     * @return The total cost of the resource.
     */
    int getTotalCost() const;

    /**
     * @brief Returns the current quantity of the resource.
     * @return The quantity of the resource.
     */
    int getQuantity() const;

    /**
     * @brief Replenishes the resource by adding a specified amount.
     * @param amount The amount to add to the resource quantity.
     */
    void replenish(int amount);

    /**
     * @brief Retrieves the building type for this resource product.
     * @return A string representing the building type.
     */
    std::string getBuildingType() {
        return "ConstructionResourceProduct";
    }

    /**
     * @brief Retrieves the unit cost of the resource.
     * @return The unit cost of the resource.
     */
    int getUnitCost() const;

    /**
     * @brief Checks if the resource is ready for collection.
     * @return True if the resource is ready for collection, false otherwise.
     */
    bool isReadyForCollection();

    /**
     * @brief Allows tax collection on the resource by accepting a tax collector.
     * @param TC The tax collector.
     */
    virtual void accept(taxCollector* TC) {}

    /**
     * @brief Retrieves the name of the resource.
     * @return The name of the resource.
     */
    std::string getName() const {
        return name;
    }

    /**
     * @brief Sets the location of the resource.
     * @param loc The location to set for the resource.
     */
    void setLocation(const Location& loc) { location = loc; }

    /**
     * @brief Retrieves the location of the resource.
     * @return The location of the resource.
     */
    Location getLocation() const { return location; }
};

#endif
