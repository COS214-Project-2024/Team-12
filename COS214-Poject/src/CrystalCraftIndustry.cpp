/**
 * @file CrystalCraftIndustry.cpp
 * @brief Implementation of the CrystalCraftIndustry class for processing diamond and stone resources.
 */

#include "CrystalCraftIndustry.h"

/**
 * @brief Constructs a CrystalCraftIndustry with specified diamond and stone resources, along with map grid and collected resources.
 * 
 * Initializes the industry with processors for income and construction resources, setting up the 
 * necessary infrastructure for resource processing.
 * 
 * @param diamond Shared pointer to an IncomeResourceProduct representing diamond.
 * @param stone Shared pointer to a ConstructionResourceProduct representing stone.
 * @param grid Pointer to the MapGrid object, which manages the industry's location and layout.
 * @param collectedResources Reference to a map of collected resources for the city.
 */
CrystalCraftIndustry::CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                                           std::shared_ptr<ConstructionResourceProduct> stone, 
                                           MapGrid* grid, 
                                           std::map<std::string, int>& collectedResources)
    : Industry("Crystal Craft Industry",
               std::make_shared<IncomeResourceProcessor>(diamond, 200),
               std::make_shared<ConstructionResourceProcessor>(stone, 200), 
               grid,  
               collectedResources, 
               CRYSTAL_CRAFT_RANGE) {}

/**
 * @brief Processes a specified amount of diamond, contributing to the city's income resources.
 * 
 * The method uses the income resource processor to convert diamond quantities into processed output.
 * 
 * @param amount The amount of diamond to process.
 */
void CrystalCraftIndustry::processDiamond(int amount) {
    std::cout << "Processing diamond in Crystal Craft industry...\n";
    processResources(amount, true);
}

/**
 * @brief Processes a specified amount of stone, contributing to the city's construction resources.
 * 
 * The method uses the construction resource processor to convert stone quantities into processed output.
 * 
 * @param amount The amount of stone to process.
 */
void CrystalCraftIndustry::processStone(int amount) {
    std::cout << "Processing stone in Crystal Craft industry...\n";
    processResources(amount, false);
}
