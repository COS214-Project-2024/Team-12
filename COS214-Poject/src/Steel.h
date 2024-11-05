#ifndef STEEL_H
#define STEEL_H

#include "ConstructionResourceProduct.h" 
#include <iostream>
#include <string>

/**
 * @class Steel
 * @brief Represents the Steel resource in the city simulation.
 * 
 * This class is a concrete product derived from ConstructionResourceProduct.
 * It encapsulates the properties and behavior of Steel used in construction.
 */
class Steel : public ConstructionResourceProduct { 

public:
    /**
     * @brief Constructs a Steel object with specified quantity and unit cost.
     * 
     * Initializes the Steel resource with a given quantity and cost per unit.
     * 
     * @param quantity The initial quantity of Steel.
     * @param unitCost The cost per unit of Steel.
     */
    Steel(int quantity, int unitCost);

    /**
     * @brief Destructor for Steel.
     * 
     * Cleans up any resources or states when a Steel object is destroyed.
     */
    ~Steel();

    /**
     * @brief Displays the current status of the Steel resource.
     * 
     * Provides detailed information about the quantity, unit cost, and total cost of the Steel.
     */
    void displayStatus() override;

    /**
     * @brief Gets the type of building resource.
     * 
     * @return The type of the building resource as a string, in this case, "Steel".
     */
    std::string getBuildingType() const {
        return "Steel";
    }
};

#endif
