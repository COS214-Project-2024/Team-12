/**
 * @file CulturalCenterFactory.cpp
 * @brief Implementation of the CulturalCenterFactory class for creating CulturalCenter landmarks.
 */

#include "CulturalCenterFactory.h"
#include "CulturalCenter.h"

/**
 * @brief Creates a new instance of CulturalCenter with default parameters.
 * 
 * This function constructs a CulturalCenter landmark with default values for type, capacity, 
 * price, and utility connections.
 * 
 * @return A unique pointer to a new CulturalCenter instance.
 */
std::unique_ptr<LandMark> CulturalCenterFactory::createLandMark() {
    return std::make_unique<CulturalCenter>("DefaultType", 0, 0.0, nullptr, nullptr, nullptr, nullptr);
}
