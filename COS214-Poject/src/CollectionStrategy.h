#ifndef COLLECTIONSTRATEGY_H
#define COLLECTIONSTRATEGY_H

/**
 * @class CollectionStrategy
 * @brief Abstract base class for resource collection strategies in the game.
 * 
 * Defines the interface for various strategies that determine how resources 
 * are collected. Concrete strategies derived from this class will implement 
 * specific collection behaviors.
 */
class CollectionStrategy {
public:
    /**
     * @brief Virtual destructor for the CollectionStrategy class.
     * 
     * Ensures proper cleanup of resources for derived classes.
     */
    virtual ~CollectionStrategy() = default;

    /**
     * @brief Pure virtual function to collect resources based on a strategy.
     * 
     * Derived classes implement this method to adjust the amount collected
     * based on a specific collection strategy.
     * 
     * @param baseAmount The base amount to be collected.
     * @return The adjusted amount collected based on the strategy.
     */
    virtual int collect(int baseAmount) const = 0;
};

#endif
