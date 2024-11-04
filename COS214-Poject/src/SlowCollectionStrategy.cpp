#include "SlowCollectionStrategy.h"

/**
 * @brief Collects resources based on a slow strategy.
 * 
 * This method simulates a slow collection rate by halving the base amount.
 * 
 * @param baseAmount The base amount of resources to be collected.
 * @return int Adjusted amount of resources collected according to the slow strategy.
 */
int SlowCollectionStrategy::collect(int baseAmount) {
    return baseAmount / 2; // Slower collection rate
}
