#ifndef COLLECTIONSTRATEGY_H
#define COLLECTIONSTRATEGY_H

class CollectionStrategy {
public:
    virtual ~CollectionStrategy() = default;
    virtual int collect(int baseAmount) const = 0;
};

#endif