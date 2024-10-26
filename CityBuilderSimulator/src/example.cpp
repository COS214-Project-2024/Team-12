#include "project/example.h"
#include <stdexcept>
#include <climits>  // Added this header for INT_MAX and INT_MIN

namespace project {

int Example::add(int a, int b) {
    // Check for overflow
    if ((b > 0 && a > INT_MAX - b) || 
        (b < 0 && a < INT_MIN - b)) {
        throw std::overflow_error("Integer overflow in addition");
    }
    return a + b;
}

} // namespace project