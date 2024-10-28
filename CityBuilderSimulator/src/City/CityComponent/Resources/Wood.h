#ifndef WOOD_H
#define WOOD_H

#include "ConstructionResourceProduct.h"  // Assuming ConstructionResourceProduct is the base class
#include <iostream>
#include <string>

class Wood : public ConstructionResourceProduct {  // Public inheritance
public:
    // Constructor
    Wood(int quantity, int unitCost);

    // Destructor
    ~Wood();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
