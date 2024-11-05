#include "ParkFactory.h"
#include "Park.h"

/**
 * @brief Creates a new Park object.
 * 
 * This method creates a unique pointer to a new Park instance, 
 * which can be used to represent a park in the city simulation.
 * 
 * @return A unique pointer to a newly created Park object.
 */
std::unique_ptr<LandMark> ParkFactory::createLandMark() {
    return std::make_unique<Park>();
}
