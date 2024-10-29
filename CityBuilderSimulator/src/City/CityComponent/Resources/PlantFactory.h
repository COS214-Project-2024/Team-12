#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

class PlantFactory : public ResourceFactory {
public:
    PlantFactory();
    ~PlantFactory();

    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
