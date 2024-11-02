#ifndef COLLECT_TAX_RESIDENTIAL_H
#define COLLECT_TAX_RESIDENTIAL_H


#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "ResidentialZoneComposite.h"
#include "Government.h"
#include "CommercialZoneComposite.h"
#include "House.h"
#include "Estate.h"
#include "Townhouse.h"
#include "Flat.h"


class CollectTaxResidential{
    public:
    // virtual void visit(ResidentialBuilding* RB)=0;
    // virtual void visit(CommercialBuilding* CB)=0;
    // virtual void visit(ResidentialZoneComposite* Rzone)=0;
    // virtual void visit(CommercialZoneComposite* Czone)=0;
    // virtual ~CollectTaxResidential();
    // Government* bank;

    virtual void visit(House* house)=0;
    virtual void visit(Estate* estate)=0;
    virtual void visit(Townhouse* townhouse)=0;
    virtual void visit(Flat* flat)=0;
    CollectTaxResidential();
    virtual ~CollectTaxResidential();
  
   




};


#endif