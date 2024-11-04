#ifndef POLICESTATION_H
#define POLICESTATION_H

#include "PublicService.h"

/**
 * @class PoliceStation
 * @brief Represents a police station, which is a public service in the city.
 *
 * The PoliceStation class inherits from the PublicService class and provides methods to manage its utilities
 * and display its status.
 */
class PoliceStation : public PublicService {
private:
    std::string status; ///< The operational status of the police station.
public:
    /**
     * @brief Default constructor for PoliceStation.
     */
    PoliceStation() = default;

    /**
     * @brief Constructs a PoliceStation with specified utilities and status.
     * 
     * @param water Shared pointer to the water utility.
     * @param electricity Shared pointer to the electricity utility.
     * @param wasteManagement Shared pointer to the waste management utility.
     * @param sewage Shared pointer to the sewage utility.
     * @param buildingStatus The operational status of the police station.
     */
    PoliceStation(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
                  std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
                  std::string buildingStatus);

    /**
     * @brief Default destructor for PoliceStation.
     */
    ~PoliceStation() = default;

    /**
     * @brief Provides police services to ensure public safety.
     */
    void provideService() override {
        std::cout << "Police Station is ensuring public safety.\n";
    }

    /**
     * @brief Creates a clone of the PoliceStation object.
     * 
     * @return A unique pointer to the cloned PoliceStation object.
     */
    std::unique_ptr<PublicService> clone() const;

    /**
     * @brief Displays the current status of the Police Station.
     * 
     * This includes the connection status of water, electricity, waste management, sewage,
     * and the overall operational status of the police station.
     */
    void displayStatus() override;

    /**
     * @brief Retrieves the display symbol for the Police Station.
     * 
     * @return The character symbol representing the Police Station ('P').
     */
    char getDisplaySymbol() const override;
};

#endif
