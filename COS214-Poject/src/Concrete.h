#ifndef CONCRETE_H
#define CONCRETE_H

#include "ConstructionResourceProduct.h"  
#include <iostream>

class Concrete : public ConstructionResourceProduct {
public:
    Concrete(int quantity, int unitCost);

  
    ~Concrete();
    void displayStatus() override;

    std::string getBuildingType() const {
		return "Concrete";
	}
};

#endif
