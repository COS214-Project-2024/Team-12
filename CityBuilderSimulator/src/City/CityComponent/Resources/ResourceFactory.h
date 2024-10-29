#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include "IncomeResourceProduct.h"     
#include "ConstructionResourceProduct.h"
#include <memory>

class ResourceFactory {
public:
    ResourceFactory() = default;
    virtual ~ResourceFactory() = default;


    virtual std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) = 0;
    virtual std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) = 0;
};

#endif
