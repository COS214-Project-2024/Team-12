#ifndef VISIT_RESIDENTIAL_H
#define VISIT_RESIDENTIAL_H

#include "CollectTaxResidential.h"
#include "House.h"
#include "Flat.h"
#include "Estate.h"
#include "Townhouse.h"
#include "Government.h"

class VisitResidential: public CollectTaxResidential{

     void visit(House* house);
     void visit(Estate* estate);
     void visit(Townhouse* townhouse);
     void visit(Flat* flat);
     VisitResidential();
    

};



#endif