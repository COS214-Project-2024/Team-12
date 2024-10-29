#ifndef CRYSTALCRAFTINDUSTRY_H
#define CRYSTALCRAFTINDUSTRY_H

#include "Industry.h"

// Concrete Industry: Glass & Gem Works
class CrystalCraftIndustry : public Industry {
public:
    CrystalCraftIndustry();
    CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                     std::shared_ptr<ConstructionResourceProduct> stone);
};

#endif