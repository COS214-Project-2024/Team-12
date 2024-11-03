#ifndef WOODANDCOALPLANT_H
#define WOODANDCOALPLANT_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Lumber & Coal Plant
class WoodAndCoalPlant : public Industry {
public:
    WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
                    std::shared_ptr<ConstructionResourceProduct> wood)
        : Industry("Wood and Coal Plant",
                std::make_shared<IncomeResourceProcessor>(coal, 200),
                std::make_shared<ConstructionResourceProcessor>(wood, 200)) {}

    // Specialized processing for wood and coal plant
    void processCoal(int amount) {
        std::cout << "Processing coal in Wood and Coal plant...\n";
        processResources(amount, true);
    }

    void processWood(int amount) {
        std::cout << "Processing wood in Wood and Coal plant...\n";
        processResources(amount, false);
    }
};

#endif
