#ifndef STONE_H
#define STONE_H

#include "ConstructionResourceProduct.h"  // Assuming ConstructionResourceProduct is the base class
#include <iostream>
#include <string>

class Stone : public ConstructionResourceProduct {  // Public inheritance
public:
    // Constructor
    Stone(int quantity, int unitCost);

    // Destructor
    ~Stone();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
