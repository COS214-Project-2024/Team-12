// PetrochemicalFacility.cpp
#include "PetrochemicalFacility.h"

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

void PetrochemicalFacility::processOil(int amount) {
    std::cout << "Processing oil in Petrochemical facility...\n";
    processResources(amount, true);
}

void PetrochemicalFacility::processConcrete(int amount) {
    std::cout << "Processing concrete in Petrochemical facility...\n";
    processResources(amount, false);
}