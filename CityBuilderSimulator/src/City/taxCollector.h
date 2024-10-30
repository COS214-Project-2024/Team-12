#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H



#include "CityComponent/Residential/ResidentialBuilding.h"
#include "CityComponent/Residential/ResidentialZoneComposite.h"
#include "CityComponent/Commercial/CommercialBuilding.h"

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