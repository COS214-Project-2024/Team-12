#ifndef METALFACTORY_H
#define METALFACTORY_H

#include "ResourceFactory.h"
#include "../../CityComponent/Resources/IncomeResourceProduct.h"
#include "../../CityComponent/Resources/ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

class MetalFactory : public ResourceFactory {
public:
    MetalFactory();
    ~MetalFactory();

    
    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
