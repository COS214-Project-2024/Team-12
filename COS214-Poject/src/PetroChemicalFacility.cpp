// PetrochemicalFacility.cpp
#include "PetroChemicalFacility.h"

/**
 * @brief Constructor for the PetrochemicalFacility class.
 * 
 * Initializes a PetrochemicalFacility with specified resources, 
 * processing capabilities, and a grid for resource management.
 * 
 * @param oil A shared pointer to an IncomeResourceProduct representing oil.
 * @param concrete A shared pointer to a ConstructionResourceProduct representing concrete.
 * @param grid A pointer to the MapGrid for resource allocation and management.
 * @param collectedResources A reference to a map that tracks collected resources.
 */
PetrochemicalFacility::PetrochemicalFacility(
    std::shared_ptr<IncomeResourceProduct> oil,
    std::shared_ptr<ConstructionResourceProduct> concrete,
    MapGrid* grid,
    std::map<std::string, int>& collectedResources)
    : Industry("Petrochemical Facility",
              std::make_shared<IncomeResourceProcessor>(oil, 200),
              std::make_shared<ConstructionResourceProcessor>(concrete, 200),
              grid,
              collectedResources,
              PETRO_CHEMICAL_RANGE) {}

/**
 * @brief Processes a specified amount of oil in the facility.
 * 
 * This method processes the given amount of oil and updates the 
 * collected resources accordingly.
 * 
 * @param amount The amount of oil to be processed.
 */
void PetrochemicalFacility::processOil(int amount) {
    std::cout << "Processing oil in Petrochemical facility...\n";
    processResources(amount, true);
}

/**
 * @brief Processes a specified amount of concrete in the facility.
 * 
 * This method processes the given amount of concrete and updates 
 * the collected resources accordingly.
 * 
 * @param amount The amount of concrete to be processed.
 */
void PetrochemicalFacility::processConcrete(int amount) {
    std::cout << "Processing concrete in Petrochemical facility...\n";
    processResources(amount, false);
}
