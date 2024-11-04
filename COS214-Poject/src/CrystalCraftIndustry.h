#ifndef CRYSTALCRAFTINDUSTRY_H
#define CRYSTALCRAFTINDUSTRY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Glass & Gem Works
class CrystalCraftIndustry : public Industry {
public:
    static const int CRYSTAL_CRAFT_RANGE = 5;

    CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                    std::shared_ptr<ConstructionResourceProduct> stone, MapGrid* grid,  std::map<std::string, int>& collectedResources);
    // Specialized processing for metal work
    void processDiamond(int amount);

    void processStone(int amount) ;
};

#endif