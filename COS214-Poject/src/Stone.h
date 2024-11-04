#ifndef STONE_H
#define STONE_H

#include "ConstructionResourceProduct.h"  
#include <iostream>
#include <string>

/**
 * @class Stone
 * @brief Represents a construction resource product of type Stone.
 * 
 * Inherits from `ConstructionResourceProduct` and provides additional
 * functionality specific to stone resources, including cost and quantity tracking.
 */
class Stone : public ConstructionResourceProduct {  
public:
    /**
     * @brief Constructs a Stone object with a specified quantity and unit cost.
     * 
     * @param quantity The initial quantity of Stone.
     * @param unitCost The cost per unit of Stone.
     */
    Stone(int quantity, int unitCost);

    /**
     * @brief Destructor for Stone.
     * 
     * Outputs a message to the console when the Stone object is destroyed.
     */
    ~Stone();

    /**
     * @brief Displays the current status of the Stone resource.
     * 
     * Overrides the `displayStatus` method from `ConstructionResourceProduct`
     * to provide specific information related to Stone resources.
     */
    void displayStatus() override;

    /**
     * @brief Gets the type of building resource.
     * 
     * @return A string indicating the resource type, "Stone".
     */
    std::string getBuildingType() const override {
		return "Stone";
	}
};

#endif
