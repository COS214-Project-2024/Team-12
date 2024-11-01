//CONCRETE OBSERVER
#ifndef CONSTRUCTIONDELIVERYTRUCK_H
#define CONSTRUCTIONDELIVERYTRUCK_H

#include <iostream>
#include "ConstructionTruck.h"
#include "Steel.h"
#include "Concrete.h"
#include "Wood.h"
#include "Stone.h"

class ConstructionDeliveryTruck : public ConstructionTruck {
private:
    Steel* SteelSubject;
    Concrete* ConcreteSubject;
    Stone* StoneSubject;
    Wood* WoodSubject;

public:
    void update();
};
#endif