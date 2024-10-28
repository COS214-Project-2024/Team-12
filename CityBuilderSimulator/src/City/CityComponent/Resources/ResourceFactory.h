#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include "IncomeResourceProduct.h"       // Include these to use the product classes
#include "ConstructionResourceProduct.h"

class ResourceFactory {


public:
	void ResourceFactory(){};
	virtual ~ResourceFactory(){};

	virtual IncomeResourceProduct* createIncomeR(int quantity) = 0;

	virtual ConstructionResourceProduct* createConstructionR(int quantity) = 0;
};

#endif
