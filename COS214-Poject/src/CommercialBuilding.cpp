/**
 * @file CommercialBuilding.cpp
 * @brief Implementation of the CommercialBuilding class, handling commercial building attributes, utilities, and tax functionalities.
 */

#include "CommercialBuilding.h"
#include "NPCManager.h"
#include "taxCollector.h"
#include <iostream>

/**
 * @brief Constructs a CommercialBuilding with specified price and utility connections.
 * 
 * Initializes the building with a price and establishes connections to water, 
 * power, waste, and sewage utilities if provided.
 * 
 * @param price The cost of the commercial building.
 * @param water Shared pointer to the water supply utility.
 * @param power Shared pointer to the power supply utility.
 * @param waste Shared pointer to waste management utility.
 * @param sewage Shared pointer to sewage management utility.
 */
CommercialBuilding::CommercialBuilding(double price,
                                       std::shared_ptr<UtilityFlyweight> water,
                                       std::shared_ptr<UtilityFlyweight> power,
                                       std::shared_ptr<UtilityFlyweight> waste,
                                       std::shared_ptr<UtilityFlyweight> sewage)
    : price(price), taxPaid(false),
      waterSupply(std::move(water)), powerSupply(std::move(power)),
      wasteManagement(std::move(waste)), sewageManagement(std::move(sewage)) {}

/**
 * @brief Displays the status of the commercial building.
 * 
 * Outputs the building's type, price, tax status, and utility coverage to the console.
 */
void CommercialBuilding::displayStatus() {
    std::cout << "Building Type: " << getBuildingType() << "\n"
              << "Price: $" << price << "\n"
              << "Tax Status: " << (taxPaid ? "Paid" : "Unpaid") << "\n"
              << "Utilities Connected: " << getUtilityCoverage() << "/4\n";
}

/**
 * @brief Accepts a tax collector to process tax collection for this building.
 * 
 * Invokes the tax collector's visit method, enabling tax processing for the building.
 * 
 * @param TC Pointer to the tax collector.
 */
void CommercialBuilding::accept(taxCollector* TC) {
    if (TC) TC->visit(this);
}

/**
 * @brief Sets the tax-paid status for the commercial building.
 * 
 * Marks the tax as paid and, if paid, increases the employment rate 
 * to reflect the positive economic impact.
 * 
 * @param paid Boolean indicating whether tax has been paid.
 */
void CommercialBuilding::setTaxPaid(bool paid) {
    taxPaid = true;
    if (paid) {
        // Commercial tax payments might affect employment rate
        Government::getInstance().increaseEmploymentRate(1.0);
    }
}

/**
 * @brief Retrieves the building type as a string.
 * 
 * @return A string representing the building type ("Commercial Building").
 */
std::string CommercialBuilding::getBuildingType() const {
    return "Commercial Building";
}

/**
 * @brief Calculates the utility coverage for the building.
 * 
 * Counts the number of connected utilities (water, power, waste, sewage) and returns the total.
 * 
 * @return An integer representing the number of connected utilities (0 to 4).
 */
int CommercialBuilding::getUtilityCoverage() const {
    int coverage = 0;
    if (waterSupply) coverage++;
    if (powerSupply) coverage++;
    if (wasteManagement) coverage++;
    if (sewageManagement) coverage++;
    return coverage;
}
