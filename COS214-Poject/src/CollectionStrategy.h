#ifndef COLLECTIONSTRATEGY_H
#define COLLECTIONSTRATEGY_H

#include "IncomeResourceProduct.h"
#include "ConstructionResourceProduct.h"
#include <memory>

class CollectionStrategy {
public:
    virtual ~CollectionStrategy() = default;
    virtual int collect(int baseAmount) const = 0;
};

#endif