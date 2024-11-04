#ifndef PETROCHEMICALFACILITY_H
#define PETROCHEMICALFACILITY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Petrochemical Facility
class PetrochemicalFacility : public Industry {
public:
    static const int PETRO_CHEMICAL_RANGE = 5;

    PetrochemicalFacility(std::shared_ptr<IncomeResourceProduct> oil,
                    std::shared_ptr<ConstructionResourceProduct> concrete, MapGrid* grid,  std::map<std::string, int>& collectedResources);
    // Specialized processing for {Petrochecmical}
    void processOil(int amount);
    void processConcrete(int amount) ;
};

#endif