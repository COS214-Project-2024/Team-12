#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H

#include "taxCollector.h"
#include "Government.h"
#include "ResidentialZoneComposite.h"


class ConcreteTaxCollector: public taxCollector{
    public:
     void visit(ResidentialBuilding* RB);
     void visit(CommercialBuilding* CB);
     void visit(ResidentialZoneComposite* Rzone);
     Government* bank;
    

};


#endif