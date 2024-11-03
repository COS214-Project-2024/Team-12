#include "MetalWorkFacility.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"
#include <iostream>

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

void MetalWorkFacility::processGold(int amount) {
    std::cout << "Processing gold in Metal Work facility...\n";
    processResources(amount, true);
}

void MetalWorkFacility::processSteel(int amount) {
    std::cout << "Processing steel in Metal Work facility...\n";
    processResources(amount, false);
}
