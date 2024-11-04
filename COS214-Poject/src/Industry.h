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

/**
 * @brief Represents an industrial facility in the city.
 * 
 * The Industry class inherits from CityComponent and is responsible for processing resources, 
 * managing pollution, and interacting with resources in the vicinity. It supports income and 
 * construction resources and integrates with a city map grid.
 */
class Industry : public CityComponent {
protected:
    std::string name; ///< Name of the industry
    std::shared_ptr<ResourceProcessor> primaryProcessor; ///< Processor for primary resource
    std::shared_ptr<ResourceProcessor> secondaryProcessor; ///< Processor for secondary resource
    int pollutionLevel; ///< Pollution level caused by the industry
    int collectionRange; ///< Range in which the industry can collect resources
    MapGrid* grid; ///< Pointer to the map grid for location purposes
    std::shared_ptr<IncomeResourceProduct> incomeResource; ///< Income resource for the industry
    std::shared_ptr<ConstructionResourceProduct> constructionResource; ///< Construction resource for the industry
    std::map<std::string, int>& collectedResources; ///< Reference to collected resources map

public:
    /**
     * @brief Constructs an Industry object with the specified parameters.
     * 
     * @param name Name of the industry
     * @param primary Primary resource processor
     * @param secondary Secondary resource processor
     * @param grid Pointer to the map grid
     * @param collectedResources Map of collected resources
     * @param range Collection range of the industry
     */
    Industry(const std::string& name,
             std::shared_ptr<ResourceProcessor> primary,
             std::shared_ptr<ResourceProcessor> secondary,
             MapGrid* grid,
             std::map<std::string, int>& collectedResources,
             int range = 1);

    /**
     * @brief Checks if a resource is within the collection range.
     * 
     * @param industryLoc Location of the industry
     * @param resourceLoc Location of the resource
     * @return True if the resource is within range, false otherwise
     */
    bool isResourceInRange(const Location& industryLoc, const Location& resourceLoc) const;

    /**
     * @brief Gets the collection range of the industry.
     * 
     * @return Collection range as an integer
     */
    int getCollectionRange() const;

    /**
     * @brief Finds the location of the industry on the map.
     * 
     * @return Location of the industry
     */
    Location findIndustryLocation() const;

    /**
     * @brief Displays the collection range on the map.
     * 
     * @param loc Location to display the range from
     */
    void showCollectionRange(const Location& loc) const;

    /**
     * @brief Processes resources based on the specified amount.
     * 
     * @param amount Amount of resource to process
     * @param isIncomeResource True if processing income resources, false for construction resources
     */
    void processResources(int amount, bool isIncomeResource);

    /**
     * @brief Stores resources in the industry.
     * 
     * @param amount Amount of resource to store
     * @param toPrimary True to store in primary processor, false for secondary processor
     */
    virtual void storeResources(int amount, bool toPrimary = true);

    /**
     * @brief Displays the status of the industry, including pollution and resources.
     */
    virtual void displayStatus();

    /**
     * @brief Gets the type of building as a string.
     * 
     * @return Type of building as a string
     */
    std::string getBuildingType() const override;

    /**
     * @brief Accepts a tax collector visitor.
     * 
     * @param TC Pointer to the tax collector visitor
     */
    virtual void accept(taxCollector* TC);

protected:
    /**
     * @brief Increases pollution level by a specified amount.
     * 
     * @param amount Amount to increase pollution by
     */
    void increasePollution(int amount);

    /// Virtual destructor for Industry to allow proper cleanup of derived classes
    virtual ~Industry() = default;
};

#endif
