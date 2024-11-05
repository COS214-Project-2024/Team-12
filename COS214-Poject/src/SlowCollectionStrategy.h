#ifndef SLOWCOLLECTIONSTRATEGY_H
#define SLOWCOLLECTIONSTRATEGY_H

/**
 * @class SlowCollectionStrategy
 * @brief Strategy for slow resource collection.
 * 
 * This class defines a slow collection strategy that collects a specified amount 
 * of resources based on a base amount.
 */
class SlowCollectionStrategy {
public:
    /**
     * @brief Collects resources based on a slow strategy.
     * 
     * This method reduces the base amount to simulate a slower collection rate.
     * 
     * @param baseAmount The base amount of resources to be collected.
     * @return int Adjusted amount of resources collected according to the slow strategy.
     */
    int collect(int baseAmount);
};

#endif
