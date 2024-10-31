#ifndef INCOMERESOURCEPRODUCT_H
#define INCOMERESOURCEPRODUCT_H

#include "CityComponent.h"
#include "IncomeTruck.h"
#include <iostream>
#include <vector>
using namespace std;

class IncomeResourceProduct : public CityComponent {

private:
	string name;
	int quantity;
	double marketValue;
	bool readyForCollection;//Boolean variable to noify that resources are ready to be collected for proccessing
    std::vector<std::unique_ptr<IncomeTruck>> observerList;
public:
   IncomeResourceProduct(string name, int quantity, double marketValue);

	~IncomeResourceProduct();

	void consumeResources(int amount);

	double calculateIncome() const;

	double getMarketValue() const;

	void displayStatus() const;
	 int getQuantity() const;

	double getTaxRevenue() ;

	bool isReadyForCollection();  

	void replenish(int amount);
	
	void notify();

	void attach(std::unique_ptr<IncomeTruck> truck);

	void detach(IncomeTruck* truck);
	

};

#endif
