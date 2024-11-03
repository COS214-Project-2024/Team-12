#ifndef METALWORKFACILITY_H
#define METALWORKFACILITY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Metal Factory
class MetalWorkFacility : public Industry {
public:
    MetalWorkFacility(std::shared_ptr<IncomeResourceProduct> gold,
                    std::shared_ptr<ConstructionResourceProduct> steel)
        : Industry("Metal Work Facility",
                std::make_shared<IncomeResourceProcessor>(gold, 200),
                std::make_shared<ConstructionResourceProcessor>(steel, 200)) {}

    // Specialized processing for metal work
    void processGold(int amount) {
        std::cout << "Processing gold in Metal Work facility...\n";
        processResources(amount, true);
    }

    void processSteel(int amount) {
        std::cout << "Processing steel in Metal Work facility...\n";
        processResources(amount, false);
    }
};

#endif