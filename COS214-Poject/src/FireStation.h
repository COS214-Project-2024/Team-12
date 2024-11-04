#ifndef FIRESTATION_H
#define FIRESTATION_H

#include "PublicService.h"

/**
 * @class FireStation
 * @brief Represents a fire station in the city.
 * 
 * The FireStation class is a concrete implementation of 
 * the PublicService interface. It provides services related 
 * to fire safety and emergency response within the city.
 */
class FireStation : public PublicService {
private:
    std::string status; ///< Current status of the fire station (e.g., Operational, Out of Service).

public:
    /**
     * @brief Default constructor for FireStation.
     */
    FireStation() = default;

    /**
     * @brief Parameterized constructor for FireStation.
     * 
     * @param water Shared pointer to the water utility.
     * @param electricity Shared pointer to the electricity utility.
     * @param wasteManagement Shared pointer to the waste management utility.
     * @param sewage Shared pointer to the sewage utility.
     * @param buildingStatus Status of the fire station (e.g., Operational).
     */
    FireStation(std::shared_ptr<UtilityFlyweight> water, 
                std::shared_ptr<UtilityFlyweight> electricity,
                std::shared_ptr<UtilityFlyweight> wasteManagement, 
                std::shared_ptr<UtilityFlyweight> sewage, 
                std::string buildingStatus);

    /**
     * @brief Default destructor for FireStation.
     */
    ~FireStation() = default;

    /**
     * @brief Provides fire protection services.
     * 
     * This method implements the service provision functionality 
     * specific to the fire station.
     */
    void provideService() override;

    /**
     * @brief Clones the current FireStation object.
     * 
     * @return A unique pointer to a new FireStation object that is a clone of this one.
     */
    std::unique_ptr<PublicService> clone() const;

    /**
     * @brief Gets the display symbol for the fire station.
     * 
     * @return The character symbol representing the fire station.
     */
    char getDisplaySymbol() const override;

    /**
     * @brief Displays the current status of the fire station.
     * 
     * This method outputs relevant information about the fire 
     * station's status and operational capacity.
     */
    void displayStatus() override;

};

#endif
