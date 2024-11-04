#ifndef OIL_H
#define OIL_H

#include "IncomeResourceProduct.h"  // Assuming this is the base class
#include <iostream>
#include <string>

/**
 * @class Oil
 * @brief Represents an oil resource in the simulation.
 * 
 * The Oil class inherits from the IncomeResourceProduct and provides functionality
 * to manage the quantity and market value of oil resources. It allows for displaying
 * the current status of the oil resource.
 */
class Oil : public IncomeResourceProduct {  // Public inheritance
public:
    /**
     * @brief Constructs an Oil resource.
     * 
     * Initializes the Oil resource with a specified quantity and market value.
     * 
     * @param quantity The initial quantity of the oil resource.
     * @param marketValue The market value per unit of the oil resource.
     */
    Oil(int quantity, double marketValue);

    /**
     * @brief Destructor for the Oil resource.
     * 
     * Cleans up any resources held by the Oil object.
     */
    ~Oil();

    /**
     * @brief Displays the current status of the Oil resource.
     * 
     * Outputs the name, quantity, market value per unit, and total value of the
     * oil resource.
     */
    void displayStatus() override;

    /**
     * @brief Retrieves the building type of the resource.
     * 
     * @return A string representing the building type, which is "Oil".
     */
    std::string getBuildingType() const {
        return "Oil";
    }
};

#endif
