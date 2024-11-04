#ifndef COAL_H
#define COAL_H

#include <iostream>
#include "IncomeResourceProduct.h"

/**
 * @class Coal
 * @brief Represents a coal resource in the game, derived from IncomeResourceProduct.
 * 
 * This class provides functionality specific to coal resources, including 
 * initialization, status display, and identifying its type as "Coal".
 */
class Coal : public IncomeResourceProduct {
public:
    /**
     * @brief Constructs a Coal object with a specified quantity and market value.
     * 
     * @param quantity The initial quantity of coal.
     * @param marketValue The market value per unit of coal.
     */
    Coal(int quantity, double marketValue);

    /**
     * @brief Destructor for the Coal class.
     */
    ~Coal();

    /**
     * @brief Displays the status of the coal resource.
     * 
     * Overrides the displayStatus method to show details specific to coal.
     */
    void displayStatus() override;

    /**
     * @brief Retrieves the type of building/resource, which is "Coal" for this class.
     * 
     * @return A string representing the building type as "Coal".
     */
    std::string getBuildingType() const {
        return "Coal";
    }
};

#endif
