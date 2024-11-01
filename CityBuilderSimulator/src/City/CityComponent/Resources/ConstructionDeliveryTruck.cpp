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

#include <iostream>
#include "ConstructionDeliveryTruck.h"

void ConstructionDeliveryTruck::update() {

    if(this->ConcreteSubject->isReadyForCollection()){
        std::cout<< "Delivery truck notified. Fetching concrete and delivering to the Government." << std::endl;
        this->ConcreteSubject->ConsumeResource(90);
    }

    if(this->SteelSubject->isReadyForCollection()){
        std::cout<< "Delivery truck notified. Fetching steel and delivering to the Government." << std::endl;
        this->SteelSubject->ConsumeResource(90);

    }

    if(this->StoneSubject->isReadyForCollection()){
        std::cout<< "Delivery truck notified. Fetching stone and delivering to the Government." << std::endl;
        this->StoneSubject->ConsumeResource(90);

    }

    if(this->WoodSubject->isReadyForCollection()){
        std::cout<< "Delivery truck notified. Fetching wood and delivering to the Government." << std::endl;
        this->WoodSubject->ConsumeResource(90);

    }

}
