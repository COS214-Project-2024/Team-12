// ABSTRACT PRODUCT/PROTOTYPE
#ifndef PUBLICSERVICE_H
#define PUBLICSERVICE_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <memory>

// Forward declaration of utility classes
class UtilityFlyweight;
class Government;
class taxCollector;
class CityComposite;

/**
 * @brief Abstract base class representing a public service.
 * 
 * This class is responsible for managing utility connections and 
 * providing services to the city. It serves as a base for specific 
 * public service types (e.g., PoliceStation, FireStation).
 */
class PublicService : public CityComponent {
protected:
    std::shared_ptr<UtilityFlyweight> waterSupply;      ///< Connection to water supply utility
    std::shared_ptr<UtilityFlyweight> powerSupply;      ///< Connection to power supply utility
    std::shared_ptr<UtilityFlyweight> wasteManagement;   ///< Connection to waste management utility
    std::shared_ptr<UtilityFlyweight> sewageManagement;  ///< Connection to sewage management utility

public:
    /// Default constructor
    PublicService() = default;

    /**
     * @brief Parameterized constructor for initializing a public service.
     * 
     * @param water A shared pointer to the water utility.
     * @param power A shared pointer to the power utility.
     * @param waste A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage management utility.
     */
    PublicService(std::shared_ptr<UtilityFlyweight> water, 
                  std::shared_ptr<UtilityFlyweight> power,
                  std::shared_ptr<UtilityFlyweight> waste, 
                  std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Pure virtual function to provide a specific service.
     * 
     * This function must be implemented by derived classes.
     */
    virtual void provideService() = 0;

    /// Virtual destructor
    virtual ~PublicService() = default;

    /// Pure virtual function to display the status of the public service
    virtual void displayStatus() = 0;

    /**
     * @brief Returns the type of the building.
     * 
     * @return A string representing the building type.
     */
    std::string getBuildingType() const override {
        return "Public Service";
    }

    /// Pure virtual function to get the display symbol for the public service on a map
    virtual char getDisplaySymbol() const = 0; 

    // Utility-related methods
    /**
     * @brief Calculates the coverage of utilities connected to the public service.
     * 
     * @return The number of connected utilities.
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
     * @brief Checks if all necessary utilities are connected.
     * 
     * @return True if all utilities are connected, false otherwise.
     */
    bool hasUtilities() const {
        return waterSupply && powerSupply && 
               wasteManagement && sewageManagement;
    }

    void accept(taxCollector* TC) override {}
};

#endif
