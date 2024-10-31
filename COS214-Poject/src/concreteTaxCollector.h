#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H


#include "taxCollector.h"
#include "Government.h"

class ConcreteTaxCollector: public taxCollector{
    public:
     void visit(ResidentialBuilding* RB);
     void visit(CommercialBuilding* CB);
     void visit(ResidentialZoneComposite* Rzone);

    // Government* bank;
    //bank is not needed but can be accessed via
    //Government::getInstance()->someGovernmentMethod(); when needed

};


#endif