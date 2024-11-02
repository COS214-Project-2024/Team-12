#ifndef CONCRETETAXCOLLECTOR_H
#define CONCRETETAXCOLLECTOR_H


#include "taxCollector.h"
#include "Government.h"
#include "ZoneComposite.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "NPCManager.h"


class ConcreteTaxCollector : public taxCollector {
public:
    void visit(ResidentialBuilding* RB);

    void visit(CommercialBuilding* CB);
    void visit(ZoneComposite* Rzone);
};


#endif