/**
 * @file CrystalCraftIndustry.h
 * @brief Declaration of the CrystalCraftIndustry class, a specific type of Industry that processes diamonds and stone.
 */

#ifndef CRYSTALCRAFTINDUSTRY_H
#define CRYSTALCRAFTINDUSTRY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"
#include <memory>
#include <map>

/**
 * @class CrystalCraftIndustry
 * @brief Represents an industry focused on processing diamonds and stone for various uses.
 * 
 * This class defines specialized methods for processing diamonds and stone, leveraging specific resource processors.
 */
class CrystalCraftIndustry : public Industry {
public:
    static const int CRYSTAL_CRAFT_RANGE = 5; /**< The range within which this industry can gather resources. */

    /**
     * @brief Constructs a CrystalCraftIndustry with specific resources and map grid location.
     * 
     * @param diamond Shared pointer to an IncomeResourceProduct representing diamond.
     * @param stone Shared pointer to a ConstructionResourceProduct representing stone.
     * @param grid Pointer to the MapGrid where the industry is located.
     * @param collectedResources Reference to a map of collected resources.
     */
    CrystalCraftIndustry(std::shared_ptr<IncomeResourceProduct> diamond,
                         std::shared_ptr<ConstructionResourceProduct> stone, 
                         MapGrid* grid,  
                         std::map<std::string, int>& collectedResources);

    /**
     * @brief Processes a specified amount of diamonds.
     * 
     * @param amount The amount of diamonds to process.
     */
    void processDiamond(int amount);

    /**
     * @brief Processes a specified amount of stone.
     * 
     * @param amount The amount of stone to process.
     */
    void processStone(int amount);
};

#endif
