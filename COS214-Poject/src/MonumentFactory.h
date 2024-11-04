#ifndef MONUMENTFACTORY_H
#define MONUMENTFACTORY_H

#include "LandMarkFactory.h"
#include "LandMark.h"

/**
 * @class MonumentFactory
 * @brief Factory class for creating Monument instances.
 * 
 * The MonumentFactory class inherits from LandMarkFactory and provides
 * a method to create new Monument objects.
 */
class MonumentFactory : public LandMarkFactory {
public:
    /**
     * @brief Creates a new instance of a Monument.
     * 
     * @return std::unique_ptr<LandMark> A unique pointer to the newly created Monument.
     */
    std::unique_ptr<LandMark> createLandMark() override;
};

#endif
