#ifndef TAXLAWS_H
#define TAXLAWS_H


class TaxLaws{
    private:
    double taxRate;
    public:
    virtual void applyLaw()=0;
    virtual ~TaxLaws();

};

#endif