#include "MetalWorks.h"

MetalFactory::MetalFactory() : Industry() {}
    
MetalFactory::MetalFactory(std::shared_ptr<IncomeResourceProduct> gold, 
                std::shared_ptr<ConstructionResourceProduct> steel)
        : Industry("Metal Factory", std::move(gold), std::move(steel)) {}

// Additional customization can be added here for MetalFactory if needed