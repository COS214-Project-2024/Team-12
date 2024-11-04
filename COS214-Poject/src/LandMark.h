/**
 * @file LandMark.h
 * @brief Header file for the LandMark class, representing a landmark in the city.
 */

#ifndef LANDMARK_H
#define LANDMARK_H

#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>

/**
 * @class LandMark
 * @brief Represents a landmark within the city.
 * 
 * This class inherits from CityComponent and provides functionality
 * specific to landmarks, including utility connections and visitor
 * capacity.
 */
class LandMark : public CityComponent {
protected:
    std::string landMarkType; ///< The type of landmark
    int visitorCapacity;       ///< The maximum number of visitors the landmark can accommodate
    double price;             ///< The price associated with the landmark

    // Utility connections for area-of-effect functionality
    std::shared_ptr<UtilityFlyweight> waterSupply;      ///< Water utility connection
    std::shared_ptr<UtilityFlyweight> powerSupply;      ///< Power utility connection
    std::shared_ptr<UtilityFlyweight> wasteManagement;   ///< Waste management utility connection
    std::shared_ptr<UtilityFlyweight> sewageManagement;  ///< Sewage management utility connection

public:
    LandMark() = default;

    /**
     * @brief Constructs a LandMark with specified parameters.
     * 
     * @param type The type of the landmark.
     * @param capacity The visitor capacity of the landmark.
     * @param price The price of the landmark.
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage management utility.
     */
    LandMark(const std::string& type, int capacity, double price,
             std::shared_ptr<UtilityFlyweight> water, 
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste, 
             std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Displays the status of the landmark.
     * 
     * This method overrides the displayStatus method in CityComponent
     * to provide specific details for the landmark.
     */
    virtual void displayStatus() override;

    /**
     * @brief Gets the price of the landmark.
     * 
     * @return The price of the landmark.
     */
    double getPrice() const { return price; }

    // Utility-related methods

    /**
     * @brief Gets the number of utilities connected to the landmark.
     * 
     * @return The count of utility connections.
     */
    int getUtilityCoverage() const {
        int coverage = 0;
        if (waterSupply) coverage++;
        if (powerSupply) coverage++;
        if (wasteManagement) coverage++;
        if (sewageManagement) coverage++;
        return coverage;
    }

    /**
     * @brief Checks if all utilities are connected.
     * 
     * @return True if all utilities are connected, false otherwise.
     */
    bool hasUtilities() const {
        return waterSupply && powerSupply && 
               wasteManagement && sewageManagement;
    }

    /**
     * @brief Gets the building type of the landmark.
     * 
     * @return A string representing the type of building.
     */
    std::string getBuildingType() const override {
        return "LandMark";
    }

    /**
     * @brief Accepts a tax collector.
     * 
     * This method can be overridden by derived classes to implement
     * specific tax collection behavior.
     * 
     * @param TC Pointer to the tax collector.
     */
    void accept(taxCollector* TC) {}
};

#endif
