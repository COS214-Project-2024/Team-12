#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include <memory>
#include "Industry.h"

class IndustrialFactory {
public:
    //virtual std::unique_ptr<Industrial> createIndustry() = 0;
    virtual ~IndustrialFactory() {};
};

#endif 