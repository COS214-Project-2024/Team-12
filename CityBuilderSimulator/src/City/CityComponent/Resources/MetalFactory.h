#ifndef METALFACTORY_H
#define METALFACTORY_H

#include "ResourceFactory.h"
#include <iostream>

class MetalFactory :public ReourceFactory {


public:
	MetalFactory();
	~MetalFactory();

	IncomeResourceProduct* createIncomeR(int quantity) override;
	ConstructionResourceProduct* createConstructionR(int quantity) override;
};

#endif
