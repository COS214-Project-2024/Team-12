#ifndef METALWORKFACILITY_H
#define METALWORKFACILITY_H

#include "Industry.h"
#include <memory>
#include <map>

// Forward declarations
class IncomeResourceProduct;
class ConstructionResourceProduct;
class MapGrid;

/**
 * @brief A concrete implementation of an Industry for processing metal resources.
 *
 * The MetalWorkFacility class handles the processing of income-generating
 * and construction resources, specifically gold and steel. It maintains a
 * collection range within which it can collect resources.
 */
class MetalWorkFacility : public Industry {
public:
    /// The range within which the MetalWorkFacility can collect resources.
    static const int METAL_WORK_RANGE = 5;

    /**
     * @brief Constructs a MetalWorkFacility for processing gold and steel.
     *
     * Initializes the facility to process income-generating gold resources and
     * construction steel resources. It links to the map grid and a resource
     * collection tracker.
     *
     * @param gold A shared pointer to the income resource (gold) for processing.
     * @param steel A shared pointer to the construction resource (steel) for processing.
     * @param grid A pointer to the map grid where the facility is located.
     * @param collectedResources A reference to a map tracking collected resource quantities.
     */
    MetalWorkFacility(std::shared_ptr<IncomeResourceProduct> gold,
                      std::shared_ptr<ConstructionResourceProduct> steel,
                      MapGrid* grid,
                      std::map<std::string, int>& collectedResources);

    /**
     * @brief Processes a specified amount of gold.
     *
     * Decreases the stored quantity of gold by the specified amount and adds
     * the processed amount to collected resources.
     *
     * @param amount The amount of gold to process.
     */
    void processGold(int amount);

    /**
     * @brief Processes a specified amount of steel.
     *
     * Decreases the stored quantity of steel by the specified amount and adds
     * the processed amount to collected resources.
     *
     * @param amount The amount of steel to process.
     */
    void processSteel(int amount);
};

#endif // METALWORKFACILITY_H
