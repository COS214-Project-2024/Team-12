#ifndef COAL_H
#define COAL_H

#include <iostream>
#include "IncomeResourceProduct.h"

class Coal : public IncomeResourceProduct {


public:
	Coal(int quantity, double marketValue);

	~Coal();

	void displayStatus() override;
	std::string getBuildingType() const {
		return "Coal";
	}
};

#endif
