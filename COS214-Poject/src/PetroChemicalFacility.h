#ifndef PETROCHEMICALFACILITY_H
#define PETROCHEMICALFACILITY_H

#include "Industry.h"
#include "IncomeResourceProcessor.h"
#include "ConstructionResourceProcessor.h"

// Concrete Industry: Petrochemical Facility
class PetrochemicalFacility : public Industry {
public:
    PetrochemicalFacility(std::shared_ptr<IncomeResourceProduct> oil,
                    std::shared_ptr<ConstructionResourceProduct> concrete)
        : Industry("Petrochemical Facility",
                std::make_shared<IncomeResourceProcessor>(oil, 200),
                std::make_shared<ConstructionResourceProcessor>(concrete, 200)) {}

    // Specialized processing for {Petrochecmical}
    void processOil(int amount) {
        std::cout << "Processing oil in Petrochemical facility...\n";
        processResources(amount, true);
    }

    void processConcrete(int amount) {
        std::cout << "Processing concrete in Petrochemical facility...\n";
        processResources(amount, false);
    }
};

#endif