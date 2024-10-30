#ifndef GOLD_H
#define GOLD_H

#include "IncomeResourceProduct.h"  
#include <iostream>
#include <string>

class Gold : public IncomeResourceProduct {
public:

    Gold(int quantity, double marketValue);
    ~Gold();
    void displayStatus() override;
};

#endif
