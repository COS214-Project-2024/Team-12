#ifndef CONSTRUCTIONRESOURCEPRODUCT_H
#define CONSTRUCTIONRESOURCEPRODUCT_H

#include <string>
#include <iostream>
#include "../CityComponent.h"
#include "ConstructionTruck.h"

using namespace std;


class ConstructionResourceProduct :public CityComponent {

private:
	int quantity;
	int unitCost;
	string name;
	bool readyForCollection;
	std::vector<ConstructionTruck*> observerList;
	

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
	void notify();
	void attach(ConstructionTruck* observer);
	void detach(ConstructionTruck* observer);


};

#endif
