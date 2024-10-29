#ifndef DIAMONDS_H
#define DIAMONDS_H

#include "IncomeResourceProduct.h" 
#include <iostream>
#include <string>

class Diamonds : public IncomeResourceProduct {
public:
    
    Diamonds(int quantity, double marketValue);
    ~Diamonds();
    void displayStatus() override;
};

#endif
