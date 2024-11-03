#ifndef INDUSTRY_H
#define INDUSTRY_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include "CityComponent.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "ResourceProcessor.h"
#include "NPCSystem.h"

class Industry : public CityComponent {
protected:
    std::string name;
    std::shared_ptr<ResourceProcessor> primaryProcessor;
    std::shared_ptr<ResourceProcessor> secondaryProcessor;
    int pollutionLevel = 0;
    // std::unique_ptr<WorkerNPC> workerNPC; // Hired WorkerNPC

public:
    Industry(const std::string& name,
            std::shared_ptr<ResourceProcessor> primary,
            std::shared_ptr<ResourceProcessor> secondary)
        : name(name), 
        primaryProcessor(primary),
        secondaryProcessor(secondary),
        pollutionLevel(0) {}

    virtual void processResources(int amount, bool usePrimary = true) {
        auto processor = usePrimary ? primaryProcessor : secondaryProcessor;
        if (processor) {
            processor->process(amount);
            increasePollution(amount / 10);  // Simple pollution calculation
        }
    }

    virtual void storeResources(int amount, bool toPrimary = true) {
        auto processor = toPrimary ? primaryProcessor : secondaryProcessor;
        if (processor) {
            processor->store(amount);
        }
    }

    virtual void displayStatus() {
        std::cout << "\n=== " << name << " Status ===\n";
        if (primaryProcessor) {
            std::cout << "Primary Storage:\n";
            primaryProcessor->display();
        }
        if (secondaryProcessor) {
            std::cout << "Secondary Storage:\n";
            secondaryProcessor->display();
        }
        std::cout << "Pollution Level: " << pollutionLevel << "\n";
    }

    std::string getBuildingType() const override{
        return "Industry";
    }

    virtual void accept(taxCollector* TC) {}

protected:
    void increasePollution(int amount) {
        pollutionLevel += amount;
        if (pollutionLevel > 100) {
            std::cout << "WARNING: High pollution levels!\n";
        }
    }
};


#endif