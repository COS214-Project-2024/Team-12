#ifndef STONEFACTORY_H
#define STONEFACTORY_H

#include "ResourceFactory.h"
#include "../../CityComponent/Resources/IncomeResourceProduct.h"
#include "../../CityComponent/Resources/ConstructionResourceProduct.h"
#include <iostream>
#include <memory>

class StoneFactory : public ResourceFactory {
public:
    StoneFactory();
    ~StoneFactory();


    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif