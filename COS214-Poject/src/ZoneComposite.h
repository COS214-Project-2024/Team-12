#ifndef ZONE_COMPOSITE_H
#define ZONE_COMPOSITE_H

#include "CityComponent.h"
#include "Location.h"
#include "taxCollector.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

/**
 * @class ZoneComposite
 * @brief A composite class representing a zone in the city, containing multiple buildings and managing their operations.
 */
class ZoneComposite : public CityComponent {
private:
    /// Vector storing shared pointers to buildings in the zone.
    std::vector<std::shared_ptr<CityComponent>> buildings;

    /// Type of zone (e.g., Residential, Commercial, Industrial).
    std::string zoneType;

    /// Boundaries of the zone: bounds[0] = top-left, bounds[1] = bottom-right.
    Location bounds[2];

public:
    /**
     * @brief Constructs a ZoneComposite with a specified type and boundary locations.
     * @param type The type of the zone (e.g., Residential, Commercial).
     * @param topLeft The top-left boundary of the zone.
     * @param bottomRight The bottom-right boundary of the zone.
     */
    ZoneComposite(const std::string& type, const Location& topLeft, const Location& bottomRight);

    /**
     * @brief Adds a building component to the zone.
     * @param component Shared pointer to the building component to add.
     */
    void add(std::shared_ptr<CityComponent> component);

    /**
     * @brief Removes a building component from the zone.
     * @param component Shared pointer to the building component to remove.
     */
    void remove(std::shared_ptr<CityComponent> component);

    /**
     * @brief Displays the status of all buildings within the zone.
     */
    void displayStatus();

    /**
     * @brief Returns the building type for the zone.
     * @return The type of building as a string.
     */
    std::string getBuildingType() const;

    /**
     * @brief Accepts a taxCollector visitor to apply tax operations within the zone.
     * @param TC Pointer to a taxCollector object.
     */
    void accept(taxCollector* TC) override;

    /**
     * @brief Retrieves all buildings in the zone.
     * @return A constant reference to the vector of buildings.
     */
    const std::vector<std::shared_ptr<CityComponent>>& getBuildings() const;

    /**
     * @brief Gets the top-left boundary location of the zone.
     * @return A constant reference to the top-left Location.
     */
    const Location& getTopLeft() const;

    /**
     * @brief Gets the bottom-right boundary location of the zone.
     * @return A constant reference to the bottom-right Location.
     */
    const Location& getBottomRight() const;
};

#endif
