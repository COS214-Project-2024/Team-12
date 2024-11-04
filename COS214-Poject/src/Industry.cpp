#include "Industry.h"
#include "MapGrid.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Constructs an Industry with specified parameters.
 * 
 * @param name Name of the industry
 * @param primary Primary resource processor
 * @param secondary Secondary resource processor
 * @param grid Pointer to the map grid
 * @param collectedResources Map for tracking collected resources
 * @param range Collection range for the industry
 */
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

/**
 * @brief Checks if a resource is within the collection range.
 * 
 * @param industryLoc Location of the industry
 * @param resourceLoc Location of the resource
 * @return True if the resource is within range, false otherwise
 */
bool Industry::isResourceInRange(const Location& industryLoc, const Location& resourceLoc) const {
    return (abs(industryLoc.x - resourceLoc.x) <= collectionRange && 
            abs(industryLoc.y - resourceLoc.y) <= collectionRange);
}

/**
 * @brief Gets the collection range of the industry.
 * 
 * @return Collection range as an integer
 */
int Industry::getCollectionRange() const { 
    return collectionRange; 
}

/**
 * @brief Finds the location of the industry on the map.
 * 
 * @return Location of the industry or (-1, -1) if not found
 */
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

/**
 * @brief Displays the collection range of the industry on the map.
 * 
 * @param loc Location to display the range from
 */
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

/**
 * @brief Processes a specified amount of resources.
 * 
 * If resources are depleted, they are removed from the grid.
 * 
 * @param amount Amount of resource to process
 * @param isIncomeResource True for income resources, false for construction resources
 */
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

/**
 * @brief Stores a specified amount of resources in the specified processor.
 * 
 * @param amount Amount of resource to store
 * @param toPrimary True to store in the primary processor, false for secondary
 */
void Industry::storeResources(int amount, bool toPrimary) {
    auto processor = toPrimary ? primaryProcessor : secondaryProcessor;
    if (processor) {
        processor->store(amount);
    }
}

/**
 * @brief Displays the status of the industry, including storage and pollution level.
 */
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

/**
 * @brief Gets the building type of the industry.
 * 
 * @return Building type as a string
 */
std::string Industry::getBuildingType() const {
    return "Industry";
}

/**
 * @brief Accepts a tax collector visitor.
 * 
 * @param TC Pointer to the tax collector visitor
 */
void Industry::accept(taxCollector* TC) {}

/**
 * @brief Increases the pollution level of the industry.
 * 
 * If pollution exceeds a certain threshold, a warning is displayed.
 * 
 * @param amount Amount to increase pollution by
 */
void Industry::increasePollution(int amount) {
    pollutionLevel += amount;
    if (pollutionLevel > 100) {
        std::cout << "WARNING: High pollution levels!\n";
    }
}
