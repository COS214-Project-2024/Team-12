#ifndef CRYSTALCRAFTINDUSTRY_H
#define CRYSTALCRAFTINDUSTRY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Glass & Gem Works
class CrystalCraftIndustry : public Industry {
public:
    CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                    std::shared_ptr<ConstructionResourceProduct> stone)
        : Industry("Crystal Craft Industry",
                std::make_shared<IncomeResourceProcessor>(diamond, 200),
                std::make_shared<ConstructionResourceProcessor>(stone, 200)) {}

    // Specialized processing for metal work
    void processDiamond(int amount) {
        std::cout << "Processing diamond in Crystal Craft industry...\n";
        processResources(amount, true);
    }

    void processStone(int amount) {
        std::cout << "Processing steel in Crystal Craft industry...\n";
        processResources(amount, false);
    }
};

#endif