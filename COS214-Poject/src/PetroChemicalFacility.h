#ifndef PETROCHEMICALFACILITY_H
#define PETROCHEMICALFACILITY_H

#include "Industry.h"

// Concrete Industry: Petrochemical Facility
class PetrochemicalFacility : public Industry {
public:
    PetrochemicalFacility();
    PetrochemicalFacility(std::shared_ptr<IncomeResourceProduct> oil, 
                          std::shared_ptr<ConstructionResourceProduct> concrete);
};

#endif 