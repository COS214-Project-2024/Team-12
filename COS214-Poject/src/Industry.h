#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "CityComponent.h"
#include "Location.h"
#include "ResourceProcessor.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <memory>
#include <string>
#include <map>

// Forward declaration
class MapGrid;

class Industry : public CityComponent {
protected:
    std::string name;
    std::shared_ptr<ResourceProcessor> primaryProcessor;
    std::shared_ptr<ResourceProcessor> secondaryProcessor;
    int pollutionLevel;
    int collectionRange;    
    MapGrid* grid;          
    std::shared_ptr<IncomeResourceProduct> incomeResource;
    std::shared_ptr<ConstructionResourceProduct> constructionResource;
    std::map<std::string, int>& collectedResources;

public:
    // Constructor declaration (implementation moved to cpp)
    Industry(const std::string& name,
            std::shared_ptr<ResourceProcessor> primary,
            std::shared_ptr<ResourceProcessor> secondary,
            MapGrid* grid,
            std::map<std::string, int>& collectedResources,
            int range = 1);

    // Function declarations (implementations moved to cpp)
    bool isResourceInRange(const Location& industryLoc, const Location& resourceLoc) const;
    int getCollectionRange() const;
    Location findIndustryLocation() const;
    void showCollectionRange(const Location& loc) const;
    void processResources(int amount, bool isIncomeResource);
    virtual void storeResources(int amount, bool toPrimary = true);
    virtual void displayStatus();
    std::string getBuildingType() const override;
    virtual void accept(taxCollector* TC);

protected:
    void increasePollution(int amount);
    virtual ~Industry() = default;
};

#endif