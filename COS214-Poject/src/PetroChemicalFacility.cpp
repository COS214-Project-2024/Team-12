#include "PetrochemicalFacility.h"

PetrochemicalFacility::PetrochemicalFacility() : Industry() {}

PetrochemicalFacility::PetrochemicalFacility(std::shared_ptr<IncomeResourceProduct> oil, 
                                            std::shared_ptr<ConstructionResourceProduct> concrete)
    : Industry("Petrochemical Facility", std::move(oil), std::move(concrete)) {}

