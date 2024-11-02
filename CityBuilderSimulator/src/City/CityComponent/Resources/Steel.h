#ifndef STEEL_H
#define STEEL_H

#include "ConstructionResourceProduct.h" 
#include <iostream>
#include <string>

class Steel : public ConstructionResourceProduct { 

public:
   
    Steel(int quantity, int unitCost);

    ~Steel();
    void displayStatus() override;
};

#endif
