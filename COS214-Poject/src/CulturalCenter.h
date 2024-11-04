/**
 * @file CulturalCenter.h
 * @brief Defines the CulturalCenter class, representing a landmark structure within the city.
 */

#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

#include "LandMark.h"

/**
 * @class CulturalCenter
 * @brief Represents a cultural center landmark in the city, providing cultural activities and boosting nearby happiness.
 */
class CulturalCenter : public LandMark {
public:
    /**
     * @brief Constructs a CulturalCenter with specified attributes.
     * 
     * @param type The type of cultural center.
     * @param capacity The seating or attendance capacity of the cultural center.
     * @param price The cost of constructing the cultural center.
     * @param water Shared pointer to a UtilityFlyweight object representing the water supply.
     * @param power Shared pointer to a UtilityFlyweight object representing the power supply.
     * @param waste Shared pointer to a UtilityFlyweight object representing the waste management system.
     * @param sewage Shared pointer to a UtilityFlyweight object representing the sewage management system.
     */
    CulturalCenter(const std::string& type, int capacity, double price, 
                   std::shared_ptr<UtilityFlyweight> water, 
                   std::shared_ptr<UtilityFlyweight> power,
                   std::shared_ptr<UtilityFlyweight> waste, 
                   std::shared_ptr<UtilityFlyweight> sewage);

    /**
     * @brief Destructor for CulturalCenter.
     */
    ~CulturalCenter();

    /**
     * @brief Displays the current status of the cultural center, including capacity and utility connections.
     */
    void displayStatus();

    /**
     * @brief Gets the building type as a string.
     * 
     * @return A string indicating the building type.
     */
    std::string getBuildingType() const;

    /**
     * @brief Creates a copy of the current CulturalCenter instance.
     * 
     * @return A unique pointer to a cloned CulturalCenter object.
     */
    std::unique_ptr<LandMark> clone() const;
};

#endif // CULTURALCENTER_H
