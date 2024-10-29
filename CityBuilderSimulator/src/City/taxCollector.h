#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H


#include "../src/City/CityComponent/Residential/ResidentialBuilding.h"
#include "../src/City/CityComponent/Commercial/CommercialBuilding.h"
#include "../src/City/Government.h"


class taxCollector{
    public:
    virtual void visit(ResidentialBuilding* RB)=0;
    virtual void visit(CommercialBuilding* CB)=0;
    virtual ~taxCollector();
    Government* bank;
   




};


#endif