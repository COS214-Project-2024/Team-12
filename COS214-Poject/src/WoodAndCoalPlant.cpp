#include "WoodAndCoalPlant.h"

WoodAndCoalPlant::WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
                    std::shared_ptr<ConstructionResourceProduct> wood, MapGrid* grid,  std::map<std::string, int>& collectedResources)
        : Industry("Wood and Coal Plant",
                std::make_shared<IncomeResourceProcessor>(coal, 200),
                std::make_shared<ConstructionResourceProcessor>(wood, 200), grid, collectedResources, WOOD_COAL_RANGE) {}

    // Specialized processing for wood and coal plant
void WoodAndCoalPlant::processCoal(int amount) {
        std::cout << "Processing coal in Wood and Coal plant...\n";
        processResources(amount, true);
    }

void WoodAndCoalPlant::processWood(int amount) {
        std::cout << "Processing wood in Wood and Coal plant...\n";
        processResources(amount, false);
}