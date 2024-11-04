#include "ModerateCollectionStrategy.h"

/**
 * @brief Collects resources at a moderate rate.
 *
 * The ModerateCollectionStrategy implements a normal collection rate
 * by simply returning the base amount specified.
 *
 * @param baseAmount The base amount of resources to be collected.
 * @return The amount collected, which is equal to the base amount.
 */
int ModerateCollectionStrategy::collect(int baseAmount) {
    return baseAmount; // Normal collection rate
}
