#ifndef CITY_COMPOSITE_H
#define CITY_COMPOSITE_H

/**
 * @file CityComposite.h
 * @brief Defines the CityComposite class, which represents a composite structure containing multiple city zones.
 * 
 * The CityComposite class is a concrete implementation of the CityComponent class, representing a collection of zones
 * and managing high-level city attributes, such as zone management, budget, and happiness levels.
 */

#include "CityComponent.h"
#include "Transport.h"
#include "Government.h"
#include "taxCollector.h"
#include "MapGrid.h"
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

/**
 * @class CityComposite
 * @brief A composite class representing the entire city and containing multiple zones.
 * 
 * This class allows the addition and removal of zones (other CityComponents) and manages 
 * high-level attributes like city name, connections between zones, and the happiness level.
 */
class CityComposite : public CityComponent {
private:
    std::vector<std::shared_ptr<CityComponent>> zones; /**< Collection of city zones */
    std::string cityName; /**< Name of the city */

public:
    /**
     * @brief Constructs a new CityComposite with the given name.
     * 
     * @param name The name of the city.
     */
    CityComposite(const std::string& name);

    /**
     * @brief Destructor for CityComposite.
     * 
     * Cleans up resources allocated for the city composite, including its zones.
     */
    ~CityComposite();

    /**
     * @brief Adds a city component (zone) to the composite.
     * 
     * @param component A shared pointer to the CityComponent to add.
     */
    void add(std::shared_ptr<CityComponent> component) override;

    /**
     * @brief Removes a city component (zone) from the composite.
     * 
     * @param component A shared pointer to the CityComponent to remove.
     */
    void remove(std::shared_ptr<CityComponent> component) override;

    /**
     * @brief Displays the status of the city composite and all its zones.
     * 
     * This function iterates over all zones and displays their status information.
     */
    void displayStatus() override;

    /**
     * @brief Checks if the city meets certain conditions.
     * 
     * This function evaluates specific conditions for city management. The conditions 
     * and their checks are implemented within the function.
     * 
     * @return true if conditions are met; otherwise, false.
     */
    bool checkCityConditions();

    /**
     * @brief Returns the type of building as a string.
     * 
     * @return A string indicating this component is a "City".
     */
    std::string getBuildingType() const override {
        return "City";
    }

    /**
     * @brief Accepts a tax collector visitor.
     * 
     * Currently, this function does not perform any actions. The function is part of
     * the Visitor pattern to allow tax collectors to visit city zones and collect taxes.
     * 
     * @param tax A pointer to a taxCollector object.
     */
    void accept(taxCollector* tax) override {
        // Placeholder implementation, no tax collection for the city composite
    }

    /**
     * @brief Connects two zones with a specified transport method.
     * 
     * Establishes a connection between two city zones using the given transport object,
     * representing roads, railways, etc.
     * 
     * @param zoneA A pointer to the first zone.
     * @param zoneB A pointer to the second zone.
     * @param transport A unique pointer to the Transport object representing the connection.
     */
    void connectZones(CityComponent* zoneA, CityComponent* zoneB, std::unique_ptr<Transport> transport);

    /**
     * @brief Updates the city’s happiness level based on the addition of a new component.
     * 
     * This function modifies happiness levels to reflect the influence of newly added components,
     * such as new residential or utility zones.
     * 
     * @param component A shared pointer to the new CityComponent being added.
     */
    void updateHappinessForNewComponent(const std::shared_ptr<CityComponent>& component);

    /**
     * @brief Adjusts the city's happiness level based on the current tax rate.
     * 
     * This function recalculates happiness based on tax policies affecting citizens and zones.
     */
    void adjustHappinessBasedOnTaxRate();
};

#endif
