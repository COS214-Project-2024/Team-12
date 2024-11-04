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
	bool readyForCollection;//Boolean variable to noify that resources are ready to be collected for proccessing
	Location location;

public:
   IncomeResourceProduct(string name, int quantity, double marketValue);

	~IncomeResourceProduct();

	void consumeResources(int amount);

	double calculateIncome() const;

	double getMarketValue() const;

	void displayStatus() const;
	 int getQuantity() const;

	bool isReadyForCollection();  

	void replenish(int amount);

	void accept(taxCollector* TC) {}
		std::string getBuildingType()
	{
		return "IncomeResourceProduct";
	}

	std::string getName() const {
		return name;
	}

	void updateReadyStatus() {
    	readyForCollection = (quantity >= 150);
	}

	void setLocation(const Location& loc) { location = loc; }
    Location getLocation() const { return location; }

};

#endif
