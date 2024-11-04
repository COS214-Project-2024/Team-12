#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "CityComponent.h"
#include <iostream>
#include <string>
#include <memory>

// Forward declarations
class UtilityFlyweight;
class Government;
class taxCollector;
class CityComposite;

/**
 * @brief Represents a residential building within the city.
 *
 * The ResidentialBuilding class provides functionality for managing utility connections,
 * displaying building status, and handling tax-related actions.
 */
class ResidentialBuilding : public CityComponent {
protected:
    int bedrooms;                                   ///< Number of bedrooms in the building
    double price;                                   ///< Price of the residential building
    bool taxPaid;                                   ///< Flag indicating whether taxes are paid

    // Utility connections for area-of-effect functionality
    std::shared_ptr<UtilityFlyweight> waterSupply;  ///< Water utility connection
    std::shared_ptr<UtilityFlyweight> powerSupply;  ///< Power utility connection
    std::shared_ptr<UtilityFlyweight> wasteManagement; ///< Waste management utility connection
    std::shared_ptr<UtilityFlyweight> sewageManagement; ///< Sewage management utility connection

public:
    /**
     * @brief Constructs a ResidentialBuilding with specified utilities and attributes.
     * @param bedrooms Number of bedrooms in the building.
     * @param cost Price of the building.
     * @param water Water supply connection.
     * @param power Power supply connection.
     * @param waste Waste management connection.
     * @param sewage Sewage management connection.
     */
    ResidentialBuilding(int bedrooms, double cost, std::shared_ptr<UtilityFlyweight> water, 
                        std::shared_ptr<UtilityFlyweight> power, std::shared_ptr<UtilityFlyweight> waste, 
                        std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Sets the tax-paid status.
     * @param paid True if tax has been paid, false otherwise.
     */
    void setTaxPaid(bool paid);

    /**
     * @brief Checks if taxes have been paid.
     * @return True if taxes are paid, false otherwise.
     */
    bool isTaxPaid() const;

    /**
     * @brief Accepts a taxCollector visitor to collect taxes from this building.
     * @param TC Pointer to the tax collector.
     */
    void accept(taxCollector* TC) override;

    /**
     * @brief Gets the price of the building.
     * @return The price of the building.
     */
    double getPrice() const { return price; }

    /**
     * @brief Displays the status of the residential building.
     */
    void displayStatus() override;

    /**
     * @brief Gets the building type.
     * @return A string representing the type of the building.
     */
std::string getBuildingType() const override{
        return "Residential Building";
    }

    /**
     * @brief Gets the symbol used for map display.
     * @return A character symbol representing the building.
     */
    virtual char getDisplaySymbol() const = 0;

    /**
     * @brief Calculates the utility coverage for this building.
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
     * @brief Checks if the building has all essential utilities connected.
     * @return True if all utilities are connected, false otherwise.
     */
     bool hasUtilities() const {
        return waterSupply && powerSupply && 
            wasteManagement && sewageManagement;
    }

    // Setters for utility connections
    void setWaterSupply(std::shared_ptr<UtilityFlyweight> utility) { waterSupply = utility; }
    void setPowerSupply(std::shared_ptr<UtilityFlyweight> utility) { powerSupply = utility; }
    void setWasteManagement(std::shared_ptr<UtilityFlyweight> utility) { wasteManagement = utility; }
    void setSewageManagement(std::shared_ptr<UtilityFlyweight> utility) { sewageManagement = utility; }

    /**
     * @brief Gets the display color based on utility coverage.
     * @return ANSI color code string for the building's utility coverage status.
     */
    virtual std::string getDisplayColor() const {
        int coverage = getUtilityCoverage();
        std::cout << "Residential coverage: " << coverage << " for " << getBuildingType() << std::endl;
        if (coverage == 4) {
            return "\033[1;32m"; // Green for full
        } else if (coverage >= 2) {
            return "\033[1;33m"; // Yellow for partial
        } else {
            return "\033[1;31m"; // Red for insufficient
        }
    }
};

#endif // RESIDENTIALBUILDING_H
