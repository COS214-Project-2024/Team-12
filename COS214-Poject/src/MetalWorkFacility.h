#ifndef METALWORKFACILITY_H
#define METALWORKFACILITY_H

#include "Industry.h"

// Concrete Industry: Metal Factory
class MetalWorkFacility : public Industry {
public:
    MetalWorkFacility();
    MetalWorkFacility(std::shared_ptr<IncomeResourceProduct> gold, 
                std::shared_ptr<ConstructionResourceProduct> steel);
};

#endif  // METALWORKS_H