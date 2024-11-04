#include "Industry.h"
#include "MapGrid.h"
#include <iostream>
#include <algorithm>

Industry::Industry(const std::string& name,
                  std::shared_ptr<ResourceProcessor> primary,
                  std::shared_ptr<ResourceProcessor> secondary,
                  MapGrid* grid,
                  std::map<std::string, int>& collectedResources,
                  int range)
    : name(name),
      primaryProcessor(primary),
      secondaryProcessor(secondary),
      grid(grid),
      collectedResources(collectedResources),
      collectionRange(range),
      pollutionLevel(0)
{}

bool Industry::isResourceInRange(const Location& industryLoc, const Location& resourceLoc) const {
    return (abs(industryLoc.x - resourceLoc.x) <= collectionRange && 
            abs(industryLoc.y - resourceLoc.y) <= collectionRange);
}

int Industry::getCollectionRange() const { 
    return collectionRange; 
}

Location Industry::findIndustryLocation() const {
    for (int y = 0; y < grid->getHeight(); y++) {
        for (int x = 0; x < grid->getWidth(); x++) {
            Location loc{x, y};
            if (grid->getComponent(loc).get() == this) {
                return loc;
            }
        }
    }
    return Location{-1, -1};
}

void Industry::showCollectionRange(const Location& loc) const {
    std::cout << "Collection range for " << name << " at (" << loc.x << "," << loc.y << "):\n";
    for (int y = loc.y - collectionRange; y <= loc.y + collectionRange; y++) {
        for (int x = loc.x - collectionRange; x <= loc.x + collectionRange; x++) {
            if (x == loc.x && y == loc.y) {
                std::cout << "[I]";
            } else {
                std::cout << "[ ]";
            }
        }
        std::cout << "\n";
    }
}

void Industry::processResources(int amount, bool isIncomeResource) {
    int availableAmount = 0;

    if (isIncomeResource && incomeResource) {
        if (incomeResource->getQuantity() > 0) {
            availableAmount = std::min(amount, incomeResource->getQuantity());
            incomeResource->consumeResources(availableAmount);

            if (incomeResource->getQuantity() == 0) {
                grid->removeComponent(incomeResource->getLocation());
                grid->removeIncomeResource(incomeResource->getLocation());
                std::cout << incomeResource->getName() << " at (" << incomeResource->getLocation().x
                          << ", " << incomeResource->getLocation().y << ") has been depleted and removed.\n";
                incomeResource = nullptr;
            }
            collectedResources[incomeResource->getName()] += availableAmount;
        }
    } else if (!isIncomeResource && constructionResource) {
        if (constructionResource->getQuantity() > 0) {
            availableAmount = std::min(amount, constructionResource->getQuantity());
            constructionResource->ConsumeResource(availableAmount);

            if (constructionResource->getQuantity() == 0) {
                grid->removeComponent(constructionResource->getLocation());
                grid->removeConstructionResource(constructionResource->getLocation());
                std::cout << constructionResource->getName() << " at (" << constructionResource->getLocation().x
                          << ", " << constructionResource->getLocation().y << ") has been depleted and removed.\n";
                constructionResource = nullptr;
            }
            collectedResources[constructionResource->getName()] += availableAmount;
        }
    }
}

void Industry::storeResources(int amount, bool toPrimary) {
    auto processor = toPrimary ? primaryProcessor : secondaryProcessor;
    if (processor) {
        processor->store(amount);
    }
}

void Industry::displayStatus() {
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

std::string Industry::getBuildingType() const {
    return "Industry";
}

void Industry::accept(taxCollector* TC) {}

void Industry::increasePollution(int amount) {
    pollutionLevel += amount;
    if (pollutionLevel > 100) {
        std::cout << "WARNING: High pollution levels!\n";
    }
}