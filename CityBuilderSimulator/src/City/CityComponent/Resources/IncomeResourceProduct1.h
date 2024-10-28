#ifndef INCOMERESOURCEPRODUCT1_H
#define INCOMERESOURCEPRODUCT1_H

#include "CityComponent.h"
#include <iostream>

using namespace std;

class IncomeResourceProduct : public CityComponent {

private:
	string name;
	int quantity;
	double marketVAlue;

public:
void IncomeResoureProduct(string name, int quantity, double marketValue);

	~IncomeResourceProduct();

	void cconsueResources();

	double calculateIncome();

	double getMarketValue();
};

#endif
