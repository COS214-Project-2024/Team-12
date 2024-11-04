#ifndef MODERATECOLLECTIONSTRATEGY_H
#define MODERATECOLLECTIONSTRATEGY_H

/**
 * @class ModerateCollectionStrategy
 * @brief A strategy for collecting resources at a moderate rate.
 *
 * This class provides a method to collect resources at a normal collection rate.
 * It is part of a strategy pattern where different collection strategies can be used
 * based on the game's requirements.
 */
class ModerateCollectionStrategy {
public:
    /**
     * @brief Collect resources at a moderate rate.
     *
     * This method implements a standard collection rate by returning
     * the base amount provided.
     *
     * @param baseAmount The base amount of resources to collect.
     * @return The amount collected, which is equal to the base amount.
     */
    int collect(int baseAmount);
};

#endif // MODERATECOLLECTIONSTRATEGY_H
