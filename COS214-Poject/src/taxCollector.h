#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H



#include "ResidentialBuilding.h"

#include "ZoneComposite.h"

#include "CommercialBuilding.h"

#include "Government.h"

class ResidentialBuilding;
class CommercialBuilding;
class ZoneComposite;


class taxCollector{
    public:
    virtual void visit(ResidentialBuilding* RB)=0;
    virtual void visit(CommercialBuilding* CB)=0;

    virtual void visit(ZoneComposite* Rzone)=0;

    virtual ~taxCollector();
    Government* bank;
};


#endif