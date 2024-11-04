#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "CityComponent.h"
#include <memory>
#include <string>

class UtilityFlyweight;
class Government;
class taxCollector;

/**
 * @class CommercialBuilding
 * @brief Represents a commercial building in the city, capable of interacting with utilities and tax collection.
 * 
 * This class provides functionalities for tax management, utility connections, 
 * and displaying the building status on the city grid.
 */
class CommercialBuilding : public CityComponent {
protected:
    double price; /**< The cost of the commercial building */
    bool taxPaid; /**< Status indicating whether taxes have been paid */

    // Utility connections
    std::shared_ptr<UtilityFlyweight> waterSupply; /**< Pointer to the water supply utility */
    std::shared_ptr<UtilityFlyweight> powerSupply; /**< Pointer to the power supply utility */
    std::shared_ptr<UtilityFlyweight> wasteManagement; /**< Pointer to waste management utility */
    std::shared_ptr<UtilityFlyweight> sewageManagement; /**< Pointer to sewage management utility */

public:
    /**
     * @brief Constructs a CommercialBuilding with specified utilities and cost.
     * 
     * @param cost The price of the building.
     * @param water Pointer to the water supply utility.
     * @param power Pointer to the power supply utility.
     * @param waste Pointer to waste management utility.
     * @param sewage Pointer to sewage management utility.
     */
    CommercialBuilding(double cost,
                       std::shared_ptr<UtilityFlyweight> water,
                       std::shared_ptr<UtilityFlyweight> power,
                       std::shared_ptr<UtilityFlyweight> waste,
                       std::shared_ptr<UtilityFlyweight> sewage);

    // Tax related methods

    /**
     * @brief Accepts a tax collector to process tax collection for the building.
     * 
     * @param TC Pointer to the tax collector.
     */
    void accept(taxCollector* TC) override;

    /**
     * @brief Sets the tax-paid status for the building.
     * 
     * @param paid Boolean indicating whether tax has been paid.
     */
    void setTaxPaid(bool paid);

    /**
     * @brief Gets the price of the building.
     * 
     * @return The price of the building.
     */
    double getPrice() const { return price; }

    /**
     * @brief Checks if the tax for the building has been paid.
     * 
     * @return True if tax is paid, false otherwise.
     */
    bool isTaxPaid() const { return taxPaid; }

    // Display methods

    /**
     * @brief Gets the type of the building as a string.
     * 
     * @return The type of the building.
     */
    std::string getBuildingType() const override;

    /**
     * @brief Displays the status of the building, including utility and tax information.
     */
    void displayStatus() override;

    /**
     * @brief Gets the display symbol for the building on the city grid.
     * 
     * @return A character representing the building symbol.
     */
    virtual char getDisplaySymbol() const = 0;

    // Utility coverage

    /**
     * @brief Calculates the building's utility coverage.
     * 
     * @return An integer representing the utility coverage level.
     */
    int getUtilityCoverage() const;

    /**
     * @brief Sets the water supply utility for the building.
     * 
     * @param utility Shared pointer to the water supply utility.
     */
    void setWaterSupply(std::shared_ptr<UtilityFlyweight> utility) { waterSupply = utility; }

    /**
     * @brief Sets the power supply utility for the building.
     * 
     * @param utility Shared pointer to the power supply utility.
     */
    void setPowerSupply(std::shared_ptr<UtilityFlyweight> utility) { powerSupply = utility; }

    /**
     * @brief Sets the waste management utility for the building.
     * 
     * @param utility Shared pointer to the waste management utility.
     */
    void setWasteManagement(std::shared_ptr<UtilityFlyweight> utility) { wasteManagement = utility; }

    /**
     * @brief Sets the sewage management utility for the building.
     * 
     * @param utility Shared pointer to the sewage management utility.
     */
    void setSewageManagement(std::shared_ptr<UtilityFlyweight> utility) { sewageManagement = utility; }

    /**
     * @brief Gets the display color based on utility coverage.
     * 
     * Uses ANSI color codes to return a string representing the color: 
     * yellow for full coverage, white for partial coverage, and red for insufficient coverage.
     * 
     * @return A string containing the ANSI color code for the display color.
     */
    virtual std::string getDisplayColor() const {
        int coverage = getUtilityCoverage();
        std::cout << "Commercial coverage: " << coverage << " for " << getBuildingType() << std::endl;
        if (coverage == 4) {
            return "\033[1;33m"; // Yellow for full
        } else if (coverage >= 2) {
            return "\033[1;37m"; // White for partial
        } else {
            return "\033[1;31m"; // Red for insufficient
        }
    }
};

#endif
