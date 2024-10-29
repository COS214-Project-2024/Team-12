#ifndef SAWMILLFACTORY_H
#define SAWMILLFACTORY_H

#include "IndustrialFactory.h"
#include "CityComponent/Industrial/Industrial.h"
class SawMillFactory : public IndustrialFactory {
public:
    std::unique_ptr<Industrial> createIndustry() ;
};

#endif 
