#ifndef OILREFINERYFACTORY_H
#define OILREFINERYFACTORY_H

#include "IndustrialFactory.h"
#include "CityComponent/Industrial/Industrial.h"

class OilRefineryFactory : public IndustrialFactory {
public:
    std::unique_ptr<Industrial> createIndustry() ;

};
#endif 
