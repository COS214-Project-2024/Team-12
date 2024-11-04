#ifndef PETROCHEMICALFACILITY_H
#define PETROCHEMICALFACILITY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Petrochemical Facility
/**
 * @class PetrochemicalFacility
 * @brief Represents a petrochemical facility that processes oil and concrete.
 * 
 * The PetrochemicalFacility class is derived from the Industry class and 
 * provides functionality to process oil and concrete resources, 
 * while managing the associated pollution levels and collection ranges.
 */
class PetrochemicalFacility : public Industry {
public:
    static const int PETRO_CHEMICAL_RANGE = 5; ///< The collection range for the petrochemical facility.

    /**
     * @brief Constructs a PetrochemicalFacility with specified resources and grid.
     * 
     * @param oil A shared pointer to an IncomeResourceProduct representing oil.
     * @param concrete A shared pointer to a ConstructionResourceProduct representing concrete.
     * @param grid A pointer to the MapGrid for managing resource locations.
     * @param collectedResources A reference to a map tracking collected resources.
     */
    PetrochemicalFacility(std::shared_ptr<IncomeResourceProduct> oil,
                    std::shared_ptr<ConstructionResourceProduct> concrete, 
                    MapGrid* grid,  
                    std::map<std::string, int>& collectedResources);

    /**
     * @brief Processes a specified amount of oil in the facility.
     * 
     * This method handles the processing of the given amount of oil.
     * 
     * @param amount The amount of oil to be processed.
     */
    void processOil(int amount);

    /**
     * @brief Processes a specified amount of concrete in the facility.
     * 
     * This method handles the processing of the given amount of concrete.
     * 
     * @param amount The amount of concrete to be processed.
     */
    void processConcrete(int amount);
};

#endif
