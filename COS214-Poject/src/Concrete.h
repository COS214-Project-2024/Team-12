#ifndef CONCRETE_H
#define CONCRETE_H

#include "ConstructionResourceProduct.h"  
#include <iostream>

/**
 * @class Concrete
 * @brief Represents a concrete resource used for construction within the game.
 * 
 * This class provides specific functionality and characteristics for concrete 
 * as a construction resource, including cost and quantity management.
 */
class Concrete : public ConstructionResourceProduct {
public:
    /**
     * @brief Constructs a Concrete resource with specified quantity and unit cost.
     * 
     * @param quantity The amount of concrete units available.
     * @param unitCost The cost per unit of concrete.
     */
    Concrete(int quantity, int unitCost);

    /**
     * @brief Destructor for the Concrete class.
     */
    ~Concrete();

    /**
     * @brief Displays the current status of the concrete resource.
     * 
     * Outputs details specific to concrete, including quantity and cost, to the console.
     */
    void displayStatus() override;

    /**
     * @brief Gets the building type for this resource.
     * 
     * @return A string representing the building type ("Concrete").
     */
    std::string getBuildingType() const {
        return "Concrete";
    }
};

#endif
