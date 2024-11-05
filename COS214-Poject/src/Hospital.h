#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "PublicService.h"
#include "taxCollector.h"

/**
 * @class Hospital
 * @brief Represents a hospital that provides medical services to citizens.
 * 
 * The Hospital class inherits from PublicService and includes utilities
 * for water, electricity, sewage, and waste management.
 */
class Hospital : public PublicService {
private:
    bool water;              ///< Indicates if water supply is available.
    bool electricity;        ///< Indicates if electricity supply is available.
    bool sewage;             ///< Indicates if sewage system is connected.
    bool wasteManagement;     ///< Indicates if waste management is operational.
    std::string status;      ///< Current status of the hospital.

public:
    /**
     * @brief Default constructor.
     */
    Hospital() = default;

    /**
     * @brief Parameterized constructor for initializing the hospital.
     * 
     * @param water A shared pointer to the water utility.
     * @param electricity A shared pointer to the electricity utility.
     * @param wasteManagement A shared pointer to the waste management utility.
     * @param sewage A shared pointer to the sewage utility.
     * @param buildingStatus The status of the hospital.
     */
    Hospital(std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> electricity,
             std::shared_ptr<UtilityFlyweight> wasteManagement, std::shared_ptr<UtilityFlyweight> sewage,
             std::string buildingStatus);

    /**
     * @brief Destructor.
     */
    ~Hospital() = default;

    /**
     * @brief Provides medical services to citizens.
     */
    void provideService() override {
        std::cout << "Hospital is providing medical services.\n";
    }

    /**
     * @brief Clones the current Hospital object.
     * 
     * @return A unique pointer to a cloned Hospital object.
     */
    std::unique_ptr<PublicService> clone() const;

    /**
     * @brief Displays the current status of the hospital.
     */
    void displayStatus() override;

    /**
     * @brief Gets the display symbol for the hospital.
     * 
     * @return The character symbol representing the hospital.
     */
    char getDisplaySymbol() const override;

    /**
     * @brief Gets the building type of the hospital.
     * 
     * @return A string representing the building type.
     */
    std::string getBuildingType() const;
};

#endif
