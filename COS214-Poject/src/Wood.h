#ifndef WOOD_H
#define WOOD_H

#include "ConstructionResourceProduct.h"  
#include <iostream>
#include <string>

class Wood : public ConstructionResourceProduct { 
public:

    Wood(int quantity, int unitCost);
    ~Wood();
    void displayStatus() override;
    std::string getBuildingType() const {
		return "Wood";
	}
};

#endif
