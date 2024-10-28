#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H

#include "taxCollector.h"
#include "Government.h"

class ConcreteTaxCollector: public taxCollector{
    public:
     void visit(ResidentialBuilding* RB);
     void visit(CommercialBuilding* CB);
     Government* bank;

};


#endif