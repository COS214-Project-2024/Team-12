#ifndef WOODANDCOALPLANT_H
#define WOODANDCOALPLANT_H

#include "Industry.h"

// Concrete Industry: Lumber & Coal Plant
class WoodAndCoalPlant : public Industry {
public:
    WoodAndCoalPlant();
    WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal, 
                    std::shared_ptr<ConstructionResourceProduct> lumber);
};

#endif
