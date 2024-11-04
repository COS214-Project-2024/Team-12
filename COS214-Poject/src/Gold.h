#ifndef GOLD_H
#define GOLD_H

#include "IncomeResourceProduct.h"  
#include <iostream>
#include <string>

/**
 * @brief Class representing the Gold resource.
 * 
 * Inherits from IncomeResourceProduct and provides functionalities 
 * specific to the Gold resource, including its quantity and market value.
 */
class Gold : public IncomeResourceProduct {
public:
    /**
     * @brief Constructs a Gold object with specified quantity and market value.
     * 
     * @param quantity The amount of gold.
     * @param marketValue The market value of a single unit of gold.
     */
    Gold(int quantity, double marketValue);

    /**
     * @brief Destructor for the Gold object.
     */
    ~Gold();

    /**
     * @brief Displays the status of the gold resource.
     */
    void displayStatus() override;

    /**
     * @brief Returns the type of building represented by this resource.
     * 
     * @return A string indicating the resource type.
     */
    std::string getBuildingType() const {
        return "Gold";
    }
};

#endif
