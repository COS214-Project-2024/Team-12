#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H

#include "../src/City/taxCollector.h"
#include "../src/City/Government.h"


class ConcreteTaxCollector: public taxCollector{
    public:
    void visit(ResidentialBuilding* RB);
    void visit(CommercialBuilding* CB);
    void visit(ResidentialZoneComposite* Rzone);
    Government* bank;
    

};


#endif