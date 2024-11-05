#ifndef PARKFACTORY_H
#define PARKFACTORY_H

#include "LandMarkFactory.h"
#include "LandMark.h"

/**
 * @class ParkFactory
 * @brief Factory class for creating Park objects.
 * 
 * The ParkFactory class is responsible for creating instances of 
 * the Park class, allowing for encapsulation of the Park creation 
 * process within the city simulation.
 */
class ParkFactory : public LandMark {
public:
    /**
     * @brief Creates a new Park object.
     * 
     * This method creates and returns a unique pointer to a new Park instance.
     * 
     * @return A unique pointer to a newly created Park object.
     */
    std::unique_ptr<LandMark> createLandMark();
};

#endif
