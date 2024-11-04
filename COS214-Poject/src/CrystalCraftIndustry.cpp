#include "CrystalCraftIndustry.h"

CrystalCraftIndustry::CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                    std::shared_ptr<ConstructionResourceProduct> stone, MapGrid* grid,  std::map<std::string, int>& collectedResources)
        : Industry("Crystal Craft Industry",
                std::make_shared<IncomeResourceProcessor>(diamond, 200),
                std::make_shared<ConstructionResourceProcessor>(stone, 200), grid,  collectedResources, CRYSTAL_CRAFT_RANGE) {}

    // Specialized processing for metal work
void CrystalCraftIndustry::processDiamond(int amount) {
        std::cout << "Processing diamond in Crystal Craft industry...\n";
        processResources(amount, true);
    }

void CrystalCraftIndustry::processStone(int amount) {
    std::cout << "Processing steel in Crystal Craft industry...\n";
    processResources(amount, false);
}