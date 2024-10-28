#ifndef CHEMICALFACTORY_H
#define CHEMICALFACTORY_H

#include "ResourceFactory.h"         // Assuming ResourceFactory is a base class
#include "IncomeResourceProduct.h"    // Assuming this is the class representing income-generating resources
#include <iostream>

class ChemicalFactory : public ResourceFactory {
public:
    ChemicalFactory();
	~ChemicalFactory();

    // Creates an IncomeResourceProduct with the specified quantity
    IncomeResourceProduct* createIncomeR(int quantity) override;
	IncomeResourceProduct* createConstructionR(int quantity) override;
};

#endif
