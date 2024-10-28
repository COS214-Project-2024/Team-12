#ifndef CONSTRUCTIONRESOURCEPRODUCT_H
#define CONSTRUCTIONRESOURCEPRODUCT_H

#include <string>
#include <iostream>
#include "CityComponent.h"

using namespace std;


class ConstructionResourceProduct :public CityComponent {

private:
	int quantity;
	int unitCost;
	string name;
	

public:
void IncomeResourceProduct(string name, int quantity, int unitCost);

	 ~IncomeResourceProduct();
	void ConsumeResource();

	int displayStatus();

	int getTotalCost();

	int getQuantity();

	void replenish();
};

#endif
