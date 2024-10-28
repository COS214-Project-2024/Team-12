#ifndef OIL_H
#define OIL_H

#include "IncomeResourceProduct.h"  // Assuming this is the base class
#include <iostream>
#include <string>

class Oil : public IncomeResourceProduct {  // Public inheritance
public:
    // Constructor
    Oil(int quantity, double marketValue);

    // Destructor
    ~Oil();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
