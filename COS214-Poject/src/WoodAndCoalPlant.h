#ifndef WOODANDCOALPLANT_H
#define WOODANDCOALPLANT_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

/**
 * @class WoodAndCoalPlant
 * @brief Concrete Industry for processing lumber and coal resources.
 * 
 * This class represents a specialized industry for handling wood and coal processing. It 
 * performs specific functions to process these resources and interact with the game map grid 
 * for resource management.
 */
class WoodAndCoalPlant : public Industry {
public:
    static const int WOOD_COAL_RANGE = 5; ///< The processing range for wood and coal resources.

    /**
     * @brief Constructs a WoodAndCoalPlant with specified resource dependencies and map grid.
     * @param coal Shared pointer to the coal income resource product.
     * @param wood Shared pointer to the wood construction resource product.
     * @param grid Pointer to the map grid where the plant is located.
     * @param collectedResources Map reference to store the collected resources.
     */
    WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
                     std::shared_ptr<ConstructionResourceProduct> wood, 
                     MapGrid* grid, 
                     std::map<std::string, int>& collectedResources);

    /**
     * @brief Processes a specified amount of coal and updates resources.
     * @param amount The amount of coal to be processed.
     */
    void processCoal(int amount);

    /**
     * @brief Processes a specified amount of wood and updates resources.
     * @param amount The amount of wood to be processed.
     */
    void processWood(int amount);
};

#endif
