#ifndef STONE_H
#define STONE_H

#include "ConstructionResourceProduct.h"  
#include <iostream>
#include <string>

class Stone : public ConstructionResourceProduct {  
public:
    
    Stone(int quantity, int unitCost);

    ~Stone();
    void displayStatus() override;
    
};

#endif
