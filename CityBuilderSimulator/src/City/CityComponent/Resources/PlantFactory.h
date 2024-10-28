#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>


class PlantFactory : public ResourceFactory {
public:
    PlantFactory();
    ~PlantFactory();

    IncomeResourceProduct* createIncomeR(int quantity) override;
    ConstructionResourceProduct* createConstructionR(int quantity) override;
};

#endif
