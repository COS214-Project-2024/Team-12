#include "CrystalCraftIndustry.h"

CrystalCraftIndustry::CrystalCraftIndustry() : Industry() {}

CrystalCraftIndustry::CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                                std::shared_ptr<ConstructionResourceProduct> stone)
    : Industry("CrystalCraft Industry", std::move(diamond), std::move(stone)) {}

