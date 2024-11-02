#ifndef VISIT_COMMERCIAL_H
#define VISIT_COMMERCIAL_H

#include "CollectTaxCommercial.h"
#include "Government.h"

class VisitCommercial: public CollectTaxCommercial{

     void visit(Office* office);
     void visit(Shops* shop);
     void visit(Malls* mall);
     VisitCommercial();
    

};




#endif