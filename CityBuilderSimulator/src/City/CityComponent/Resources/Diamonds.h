#ifndef DIAMONDS_H
#define DIAMONDS_H

#include "IncomeResourceProduct.h"  // Assuming IncomeResourceProduct1 is the base class for income resources
#include <iostream>
#include <string>

class Diamonds : public IncomeResourceProduct1 {
public:
    // Constructor
    Diamonds(int quantity, double marketValue);

    // Destructor
    ~Diamonds();

    // Method to display the status of the resource
    void displayStatus() override;
};

#endif
