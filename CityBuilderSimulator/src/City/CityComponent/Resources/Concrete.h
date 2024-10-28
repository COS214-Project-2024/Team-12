#ifndef CONCRETE_H
#define CONCRETE_H

#include "ConstructionResourceProduct.h"  // Base class for construction resources
#include <iostream>

class Concrete : public ConstructionResourceProduct {
public:
    // Constructor
    Concrete(int quantity, int unitCost);

    // Destructor
    ~Concrete();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
