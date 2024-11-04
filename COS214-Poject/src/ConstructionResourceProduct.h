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
	bool readyForCollection;
	Location location;
	

public:
     ConstructionResourceProduct(string name, int quantity, int unitCost);

	 ~ConstructionResourceProduct();
	void ConsumeResource(int amount);

	void displayStatus() ;

	int getTotalCost() const;

	int getQuantity() const;

	void replenish(int amount);
	std::string getBuildingType()
	{
		return "ConstructionResourceProduct";
	}

	int getUnitCost() const;
	//double getTaxRevenue() override;
	bool isReadyForCollection(); 

	virtual void accept(taxCollector* TC) {}

	std::string getName() const {
		return name;
	}

    void setLocation(const Location& loc) { location = loc; }
    Location getLocation() const { return location; }
};

#endif
