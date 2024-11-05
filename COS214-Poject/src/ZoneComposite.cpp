#include "ZoneComposite.h"
#include "CityComponent.h"

#include <vector>
#include <string>

/**
 * @brief Constructs a ZoneComposite object with specified type and boundary coordinates.
 * @param type The type of zone (e.g., Residential, Commercial).
 * @param topLeft The top-left boundary of the zone.
 * @param bottomRight The bottom-right boundary of the zone.
 */
ZoneComposite::ZoneComposite(const std::string& type, const Location& topLeft, const Location& bottomRight)
    : zoneType(type) {
    bounds[0] = topLeft;
    bounds[1] = bottomRight;
    std::cout << "Created zone of type: " << type << " from (" 
              << topLeft.x << "," << topLeft.y << ") to ("
              << bottomRight.x << "," << bottomRight.y << ")\n";
}

/**
 * @brief Adds a building component to the zone.
 * @param component Shared pointer to the building component to add.
 */
void ZoneComposite::add(std::shared_ptr<CityComponent> component) {
    buildings.push_back(component);
}

/**
 * @brief Removes a building component from the zone.
 * @param component Shared pointer to the building component to remove.
 */
void ZoneComposite::remove(std::shared_ptr<CityComponent> component) {
    auto it = std::find(buildings.begin(), buildings.end(), component);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

/**
 * @brief Displays the status of all buildings within the zone.
 */
void ZoneComposite::displayStatus() {
    std::cout << zoneType << " Zone:\n";
    for (auto& building : buildings) {
        building->displayStatus();
    }
}

/**
 * @brief Returns the building type for the zone.
 * @return The type of building as a string.
 */
std::string ZoneComposite::getBuildingType() const {
    return zoneType;
}

/**
 * @brief Accepts a taxCollector visitor to apply tax operations within the zone.
 * @param TC Pointer to a taxCollector object.
 */
void ZoneComposite::accept(taxCollector* TC) {
    if (TC) {
        TC->visit(this);  // Let the visitor handle the iteration
    }
}
