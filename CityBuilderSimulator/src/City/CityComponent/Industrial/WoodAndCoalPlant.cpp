#include "WoodAndCoalPlant.h"

WoodAndCoalPlant::WoodAndCoalPlant() : Industry() {}

WoodAndCoalPlant::WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
        std::shared_ptr<ConstructionResourceProduct> lumber)
    : Industry("Lumber & Coal Plant", std::move(coal), std::move(lumber)) {}
