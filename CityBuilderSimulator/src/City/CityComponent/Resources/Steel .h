#ifndef STEEL_H
#define STEEL_H

#include "ConstructionResourceProduct.h"  // Assuming this is the base class
#include <iostream>
#include <string>

class Steel : public ConstructionResourceProduct {  // Public inheritance

public:
    // Constructor
    Steel(int quantity, int unitCost);

    // Destructor
    ~Steel();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
