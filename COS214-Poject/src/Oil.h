#ifndef OIL_H
#define OIL_H

#include "IncomeResourceProduct.h"  // Assuming this is the base class
#include <iostream>
#include <string>

class Oil : public IncomeResourceProduct {  // Public inheritance
public:

    Oil(int quantity, double marketValue);


    ~Oil();
    void displayStatus() override;

    std::string getBuildingType() const {
		return "Oil";
	}
};

#endif
