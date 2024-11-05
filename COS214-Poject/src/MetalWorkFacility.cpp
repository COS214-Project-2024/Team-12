#include "MetalWorkFacility.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"
#include <iostream>

/**
 * @brief Constructs a MetalWorkFacility with specific resources and a processing range.
 *
 * Initializes the MetalWorkFacility as an `Industry` specializing in processing
 * gold for income and steel for construction. Connects it to the `MapGrid` and
 * tracks collected resources.
 *
 * @param gold A shared pointer to the income-generating `IncomeResourceProduct` (Gold).
 * @param steel A shared pointer to the construction `ConstructionResourceProduct` (Steel).
 * @param grid Pointer to the `MapGrid` where the facility is located.
 * @param collectedResources Reference to a map of collected resources for tracking processed items.
 */
MetalWorkFacility::MetalWorkFacility(
    std::shared_ptr<IncomeResourceProduct> gold,
    std::shared_ptr<ConstructionResourceProduct> steel,
    MapGrid* grid,
    std::map<std::string, int>& collectedResources)
    : Industry("Metal Work Facility",
               std::make_shared<IncomeResourceProcessor>(gold, 200),
               std::make_shared<ConstructionResourceProcessor>(steel, 200),
               grid,
               collectedResources,
               METAL_WORK_RANGE) {}

/**
 * @brief Processes a specified amount of gold in the facility.
 *
 * Initiates processing for a specified quantity of gold,
 * reducing storage in the `IncomeResourceProcessor`.
 *
 * @param amount The quantity of gold to process.
 */
void MetalWorkFacility::processGold(int amount) {
    std::cout << "Processing gold in Metal Work facility...\n";
    processResources(amount, true);
}

/**
 * @brief Processes a specified amount of steel in the facility.
 *
 * Initiates processing for a specified quantity of steel,
 * reducing storage in the `ConstructionResourceProcessor`.
 *
 * @param amount The quantity of steel to process.
 */
void MetalWorkFacility::processSteel(int amount) {
    std::cout << "Processing steel in Metal Work facility...\n";
    processResources(amount, false);
}
