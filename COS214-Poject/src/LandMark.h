#ifndef LANDMARK_H
#define LANDMARK_H

#include "CityComponent.h"
#include "UtilityFlyweight.h"
#include <iostream>
#include <string>
#include <memory>

/**
 * @brief Represents a landmark building in the city with utilities and visitor capacity.
 * 
 * The `LandMark` class inherits from `CityComponent` and provides features specific
 * to landmarks, such as visitor capacity, price, and utility connections (water, power,
 * waste management, sewage).
 */
class LandMark : public CityComponent {
protected:
    std::string landMarkType; ///< The type of landmark (e.g., historical, recreational).
    int visitorCapacity; ///< Maximum capacity for visitors.
    double price; ///< Cost or entry price of the landmark.

    // Utility connections for area-of-effect functionality
    std::shared_ptr<UtilityFlyweight> waterSupply; ///< Connection to water supply utility.
    std::shared_ptr<UtilityFlyweight> powerSupply; ///< Connection to power supply utility.
    std::shared_ptr<UtilityFlyweight> wasteManagement; ///< Connection to waste management utility.
    std::shared_ptr<UtilityFlyweight> sewageManagement; ///< Connection to sewage management utility.

public:
    /**
     * @brief Default constructor for LandMark.
     */
    LandMark() = default;

    /**
     * @brief Constructs a LandMark with specified type, capacity, price, and utilities.
     * 
     * @param type Type of the landmark (e.g., museum, park).
     * @param capacity Visitor capacity of the landmark.
     * @param price Entry price or cost of the landmark.
     * @param water Shared pointer to water supply utility.
     * @param power Shared pointer to power supply utility.
     * @param waste Shared pointer to waste management utility.
     * @param sewage Shared pointer to sewage management utility.
     */
    LandMark(const std::string& type, int capacity, double price,
             std::shared_ptr<UtilityFlyweight> water, 
             std::shared_ptr<UtilityFlyweight> power,
             std::shared_ptr<UtilityFlyweight> waste, 
             std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Displays the current status of the landmark.
     * 
     * Outputs details of the landmark, such as type, visitor capacity, price,
     * and the status of each connected utility.
     */
    virtual void displayStatus() override;

    /**
     * @brief Retrieves the price of the landmark.
     * @return Price of the landmark.
     */
    double getPrice() const { return price; }

    /**
     * @brief Calculates the number of utility connections.
     * @return The number of connected utilities.
     */
    int getUtilityCoverage() const;

    /**
     * @brief Checks if all necessary utilities are connected.
     * @return `true` if all utilities (water, power, waste, sewage) are connected, `false` otherwise.
     */
    bool hasUtilities() const;

    /**
     * @brief Retrieves the building type as a string.
     * @return Building type, specifically "LandMark".
     */
    std::string getBuildingType() const override;

    /**
     * @brief Accepts a tax collector (part of the tax collection mechanism).
     * @param TC Pointer to the tax collector.
     */
    void accept(taxCollector* TC) {}
};

#endif // LANDMARK_H
