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
	

public:
     ConstructionResourceProduct(string name, int quantity, int unitCost);

	 ~ConstructionResourceProduct();
	void ConsumeResource(int amount);

	void displayStatus() ;

	int getTotalCost() const;

	int getQuantity() const;

	void replenish(int amount);

	int getUnitCost() const;
	
	bool isReadyForCollection(); 

	string getBuildingType() override;

};

#endif
