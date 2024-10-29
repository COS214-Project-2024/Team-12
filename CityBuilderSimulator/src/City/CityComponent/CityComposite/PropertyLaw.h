#ifndef SALESTAX_H
#define SALESTAX_H


#include "TaxLaws.h"

class PropertyLaw: public TaxLaws{
    private:
    double taxRate;
    public:
    void applyLaw();

};


#endif