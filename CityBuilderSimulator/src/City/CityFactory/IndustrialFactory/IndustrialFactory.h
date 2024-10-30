#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include <memory>
#include "../Industrial/Industry.h"

class IndustrialFactory {
public:
    //virtual std::unique_ptr<Industrial> createIndustry() = 0;
    virtual ~IndustrialFactory() {};
};

#endif 
