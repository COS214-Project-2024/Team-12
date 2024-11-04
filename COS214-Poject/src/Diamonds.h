/**
 * @file Diamonds.h
 * @brief Defines the Diamonds class representing an income-generating resource in the city simulation.
 */

#ifndef DIAMONDS_H
#define DIAMONDS_H

#include "IncomeResourceProduct.h" 
#include <iostream>
#include <string>

/**
 * @class Diamonds
 * @brief Represents diamonds as an income-generating resource in the city simulation.
 * 
 * The Diamonds class inherits from IncomeResourceProduct and provides functionalities
 * specific to diamond resources, including displaying their status and fetching 
 * their type.
 */
class Diamonds : public IncomeResourceProduct {
public:
    /**
     * @brief Constructs a Diamonds resource with specified quantity and market value.
     * 
     * @param quantity The amount of diamonds available.
     * @param marketValue The market value per unit of diamonds.
     */
    Diamonds(int quantity, double marketValue);

    /**
     * @brief Destructor for the Diamonds resource.
     */
    ~Diamonds();

    /**
     * @brief Displays the current status of the diamond resource.
     */
    void displayStatus() override;

    /**
     * @brief Retrieves the building type of this resource.
     * 
     * @return A string indicating the resource type, "Diamond".
     */
    std::string getBuildingType() const {
        return "Diamond";
    }
};

#endif
