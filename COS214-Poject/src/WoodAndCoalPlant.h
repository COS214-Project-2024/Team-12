#ifndef WOODANDCOALPLANT_H
#define WOODANDCOALPLANT_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Lumber & Coal Plant
class WoodAndCoalPlant : public Industry {
public:
    static const int WOOD_COAL_RANGE = 5;

    WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
                    std::shared_ptr<ConstructionResourceProduct> wood, MapGrid* grid,  std::map<std::string, int>& collectedResources);   // Specialized processing for wood and coal plant
    void processCoal(int amount);
    void processWood(int amount) ;
};

#endif
