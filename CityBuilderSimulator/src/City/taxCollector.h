#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H


#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "ResidentialZoneComposite.h"
#include "Government.h"


class taxCollector{
    public:
    virtual void visit(ResidentialBuilding* RB)=0;
    virtual void visit(CommercialBuilding* CB)=0;
    virtual void visit(ResidentialZoneComposite* Rzone)=0;
    virtual ~taxCollector();
    Government* bank;
   




};


#endif