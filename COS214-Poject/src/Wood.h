#ifndef WOOD_H
#define WOOD_H

#include "ConstructionResourceProduct.h"  
#include <iostream>
#include <string>

/**
 * @class Wood
 * @brief Represents a construction resource product of type Wood.
 * 
 * The Wood class inherits from ConstructionResourceProduct and provides specific 
 * functionality for handling wood resources, including displaying its status and 
 * identifying its type.
 */
class Wood : public ConstructionResourceProduct { 
public:

    /**
     * @brief Constructs a Wood object with specified quantity and unit cost.
     * @param quantity The quantity of wood.
     * @param unitCost The unit cost of the wood.
     */
    Wood(int quantity, int unitCost);

    /**
     * @brief Destructor for Wood.
     */
    ~Wood();

    /**
     * @brief Displays the current status of the wood resource.
     * 
     * Overrides the displayStatus method to provide wood-specific status details.
     */
    void displayStatus() override;

    /**
     * @brief Gets the building type associated with this resource.
     * @return A string representing the building type, in this case, "Wood".
     */
    std::string getBuildingType() const {
        return "Wood";
    }
};

#endif
