#ifndef METALWORKS_H
#define METALWORKS_H

#include "Industry.h"

// Concrete Industry: Metal Factory
class MetalFactory : public Industry {
public:
    MetalFactory();
    MetalFactory(std::shared_ptr<IncomeResourceProduct> gold, 
                 std::shared_ptr<ConstructionResourceProduct> steel);
};

#endif  // METALWORKS_H