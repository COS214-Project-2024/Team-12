#ifndef METALWORKFACILITY_H
#define METALWORKFACILITY_H

#include "Industry.h"


class IncomeResourceProduct;
class ConstructionResourceProduct;
class MapGrid;

// Concrete Industry: Metal Factory
class MetalWorkFacility : public Industry {
public:
    static const int METAL_WORK_RANGE = 5;

    MetalWorkFacility(std::shared_ptr<IncomeResourceProduct> gold,
                    std::shared_ptr<ConstructionResourceProduct> steel, MapGrid* grid,  std::map<std::string, int>& collectedResources);
    void processGold(int amount);
    void processSteel(int amount);
};

#endif