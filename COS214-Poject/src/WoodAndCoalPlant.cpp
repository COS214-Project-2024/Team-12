#include "WoodAndCoalPlant.h"

/**
 * @brief Constructs a WoodAndCoalPlant with specified coal and wood resources, grid, and resource collection map.
 * @param coal Shared pointer to the coal income resource product.
 * @param wood Shared pointer to the wood construction resource product.
 * @param grid Pointer to the map grid where the plant is located.
 * @param collectedResources Reference to the map storing collected resources.
 * 
 * Initializes the WoodAndCoalPlant with its specific name, income and construction resource processors, 
 * grid, resource collection map, and processing range.
 */
WoodAndCoalPlant::WoodAndCoalPlant(std::shared_ptr<IncomeResourceProduct> coal,
                                   std::shared_ptr<ConstructionResourceProduct> wood, 
                                   MapGrid* grid,  
                                   std::map<std::string, int>& collectedResources)
    : Industry("Wood and Coal Plant",
               std::make_shared<IncomeResourceProcessor>(coal, 200),
               std::make_shared<ConstructionResourceProcessor>(wood, 200), 
               grid, 
               collectedResources, 
               WOOD_COAL_RANGE) {}

/**
 * @brief Processes a specified amount of coal, updating resources accordingly.
 * @param amount The amount of coal to be processed.
 * 
 * Outputs a message to indicate coal processing and uses the inherited processResources 
 * function to handle the processing logic.
 */
void WoodAndCoalPlant::processCoal(int amount) {
    std::cout << "Processing coal in Wood and Coal plant...\n";
    processResources(amount, true);
}

/**
 * @brief Processes a specified amount of wood, updating resources accordingly.
 * @param amount The amount of wood to be processed.
 * 
 * Outputs a message to indicate wood processing and uses the inherited processResources 
 * function to handle the processing logic.
 */
void WoodAndCoalPlant::processWood(int amount) {
    std::cout << "Processing wood in Wood and Coal plant...\n";
    processResources(amount, false);
}
