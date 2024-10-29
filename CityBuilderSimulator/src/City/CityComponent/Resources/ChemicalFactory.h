#ifndef CHEMICALFACTORY_H
#define CHEMICALFACTORY_H

#include "ResourceFactory.h"        
#include "IncomeResourceProduct.h"    
#include "ConstructionResourceProduct.h" 
#include <iostream>
#include <memory>

class ChemicalFactory : public ResourceFactory {
public:
    ChemicalFactory();
    ~ChemicalFactory();


    std::unique_ptr<IncomeResourceProduct> createIncomeR(int quantity) override;
    std::unique_ptr<ConstructionResourceProduct> createConstructionR(int quantity) override;
};

#endif
