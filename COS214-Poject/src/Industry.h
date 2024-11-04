#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "ForwardDeclarations.h"
#include "CityComponent.h"
#include "Location.h"
#include "ResourceProcessor.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include "MapGrid.h"
#include <iostream>
#include <memory>
#include <string>
#include <algorithm> // For std::min

class Industry : public CityComponent {
protected:
    std::string name;
    std::shared_ptr<ResourceProcessor> primaryProcessor;
    std::shared_ptr<ResourceProcessor> secondaryProcessor;
    int pollutionLevel = 0;
    int collectionRange;    // Range for resource collection
    MapGrid* grid;          // Reference to grid
    // Removed CityGame* game; since you don't have a CityGame class
    // Declare incomeResource and constructionResource
    std::shared_ptr<IncomeResourceProduct> incomeResource;
    std::shared_ptr<ConstructionResourceProduct> constructionResource;
    std::map<std::string, int>& collectedResources;

public:
    // Constructor
    Industry(const std::string& name,
             std::shared_ptr<ResourceProcessor> primary,
             std::shared_ptr<ResourceProcessor> secondary,
             MapGrid* grid,
             std::map<std::string, int>& collectedResources,
             int range = 1)
        : name(name),
          primaryProcessor(primary),
          secondaryProcessor(secondary),
          grid(grid),
          collectedResources(collectedResources),
          collectionRange(range),
          pollutionLevel(0)
    {}

    // Check if a resource is within collection range
    bool isResourceInRange(const Location& industryLoc, const Location& resourceLoc) const {
        return (abs(industryLoc.x - resourceLoc.x) <= collectionRange && 
                abs(industryLoc.y - resourceLoc.y) <= collectionRange);
    }

    // Get collection range
    int getCollectionRange() const { return collectionRange; }

    // Find the location of the industry on the grid
    Location findIndustryLocation() const {
        for (int y = 0; y < grid->getHeight(); y++) {
            for (int x = 0; x < grid->getWidth(); x++) {
                Location loc{x, y};
                if (grid->getComponent(loc).get() == this) {
                    return loc;
                }
            }
        }
        return Location{-1, -1};  // Invalid location
    }

    // Display collection range for visualization
    void showCollectionRange(const Location& loc) const {
        std::cout << "Collection range for " << name << " at (" << loc.x << "," << loc.y << "):\n";
        for (int y = loc.y - collectionRange; y <= loc.y + collectionRange; y++) {
            for (int x = loc.x - collectionRange; x <= loc.x + collectionRange; x++) {
                if (x == loc.x && y == loc.y) {
                    std::cout << "[I]"; // Industry location
                } else {
                    std::cout << "[ ]"; // Range indicator
                }
            }
            std::cout << "\n";
        }
    }

void processResources(int amount, bool isIncomeResource) {
    int availableAmount = 0;  // Declare at the beginning

    if (isIncomeResource && incomeResource) {
        if (incomeResource->getQuantity() > 0) {
            availableAmount = std::min(amount, incomeResource->getQuantity());
            incomeResource->consumeResources(availableAmount);

            // Handle resource depletion
            if (incomeResource->getQuantity() == 0) {
                grid->removeComponent(incomeResource->getLocation());
                grid->removeIncomeResource(incomeResource->getLocation());
                std::cout << incomeResource->getName() << " at (" << incomeResource->getLocation().x
                          << ", " << incomeResource->getLocation().y << ") has been depleted and removed.\n";
                incomeResource = nullptr;
            }

            // Add to collected resources
            collectedResources[incomeResource->getName()] += availableAmount;
        }
    } else if (!isIncomeResource && constructionResource) {
        if (constructionResource->getQuantity() > 0) {
            availableAmount = std::min(amount, constructionResource->getQuantity());
            constructionResource->ConsumeResource(availableAmount);

            // Handle resource depletion
            if (constructionResource->getQuantity() == 0) {
                grid->removeComponent(constructionResource->getLocation());
                grid->removeConstructionResource(constructionResource->getLocation());
                std::cout << constructionResource->getName() << " at (" << constructionResource->getLocation().x
                          << ", " << constructionResource->getLocation().y << ") has been depleted and removed.\n";
                constructionResource = nullptr;
            }

            // Add to collected resources
            collectedResources[constructionResource->getName()] += availableAmount;
        }
    }
}


    // Store resources in processors
    virtual void storeResources(int amount, bool toPrimary = true) {
        auto processor = toPrimary ? primaryProcessor : secondaryProcessor;
        if (processor) {
            processor->store(amount);
        }
    }

    // Display industry status
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

    // Get building type
    std::string getBuildingType() const override {
        return "Industry";
    }

    // Accept tax collector (if applicable)
    virtual void accept(taxCollector* TC) {}

protected:
    // Increase pollution level
    void increasePollution(int amount) {
        pollutionLevel += amount;
        if (pollutionLevel > 100) {
            std::cout << "WARNING: High pollution levels!\n";
        }
    }

    virtual ~Industry() = default;
};

#endif
