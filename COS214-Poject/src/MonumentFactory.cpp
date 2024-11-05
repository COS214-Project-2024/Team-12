#include "MonumentFactory.h"
#include "Monument.h"

/**
 * @brief Creates a new instance of a Monument as a LandMark.
 * 
 * @return std::unique_ptr<LandMark> A unique pointer to the newly created Monument.
 */
std::unique_ptr<LandMark> MonumentFactory::createLandMark() {
    return std::make_unique<Monument>();
}
