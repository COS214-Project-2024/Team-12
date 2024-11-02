#ifndef COLLECT_TAX_COMMERCIAL_H
#define COLLECT_TAX_COMMERCIAL_H

#include "Office.h"
#include "Shops.h"
#include "Malls.h"

class CollectTaxCommercial{

    public:
    virtual void visit(Office* office)=0;
    virtual void visit(Shops* shop)=0;
    virtual void visit(Malls* mall)=0;
    CollectTaxCommercial();
    virtual ~CollectTaxCommercial();
    



};


#endif