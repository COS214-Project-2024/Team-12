#ifndef INCOMERESOURCEPRODUCT_H
#define INCOMERESOURCEPRODUCT_H

#include "CityComponent.h"
#include <iostream>
using namespace std;

class IncomeResourceProduct : public CityComponent {

private:
	string name;
	int quantity;
	double marketValue;

public:
   IncomeResourceProduct(string name, int quantity, double marketValue);

	~IncomeResourceProduct();

	void consumeResources(int amount);

	double calculateIncome() const;

	double getMarketValue() const;

	void displayStatus() const;
	 int getQuantity() const;

	double getTaxRevenue() override;
};

#endif
