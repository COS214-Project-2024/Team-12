#ifndef STONEFACTORY_H
#define STONEFACTORY_H

#include "ResourceFactory.h"
#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <iostream>

class StoneFactory : public ResourceFactory {
public:
    StoneFactory();
    ~StoneFactory();

    IncomeResourceProduct* createIncomeR(int quantity) override;
  ConstructionResourceProduct* createConstructionR(int quantity) override;
};

#endif
