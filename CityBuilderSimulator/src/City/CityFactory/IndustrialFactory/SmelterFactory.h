#ifndef SMELTERFACTORY_H
#define SMELTERFACTORY_H

#include "IndustrialFactory.h"
#include "CityComponent/Industrial/Industrial.h"

class SmelterFactory : public IndustrialFactory {
public:
    std::unique_ptr<Industrial> createIndustry() ;
};

#endif 
