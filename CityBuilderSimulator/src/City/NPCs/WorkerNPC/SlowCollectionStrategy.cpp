#include "SlowCollectionStrategy.h"

int SlowCollectionStrategy::collect(int baseAmount) {
    return baseAmount / 2; // Slower collection rate
}