#ifndef GOLD_H
#define GOLD_H

#include "IncomeResourceProduct.h"  // Assuming IncomeResourceProduct1 is the base class for income resources
#include <iostream>
#include <string>

class Gold : public IncomeResourceProduct {
public:
    // Constructor
    Gold(int quantity, double marketValue);

    // Destructor
    ~Gold();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
