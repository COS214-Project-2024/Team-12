/**
 * @file CulturalCenterFactory.h
 * @brief Defines the CulturalCenterFactory class for creating CulturalCenter landmarks.
 */

#ifndef CULTURALCENTERFACTORY_H
#define CULTURALCENTERFACTORY_H

#include "LandMarkFactory.h"
#include "LandMark.h"

/**
 * @class CulturalCenterFactory
 * @brief Factory class responsible for creating CulturalCenter landmarks.
 * 
 * The CulturalCenterFactory class inherits from LandMark and provides a method 
 * to create instances of CulturalCenter, which represent cultural landmarks in the city simulation.
 */
class CulturalCenterFactory : public LandMark {
public:
    /**
     * @brief Creates a new CulturalCenter landmark.
     * 
     * @return A unique pointer to a newly created CulturalCenter instance.
     */
    std::unique_ptr<LandMark> createLandMark();
};

#endif
