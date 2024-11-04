#include "ZoneComposite.h"
#include "CityComponent.h"

#include <vector>
#include <string>

//ZoneComposite::ZoneComposite(const std::string& type, int minX, int maxX, int minY, int maxY) : zoneType(type), minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}

// void ZoneComposite::add(CityComponent* building, int x, int y) {
//     // Check that the building type matches the zone type
//     if (building->getBuildingType() != zoneType) {
//         std::cout << "Error: Only " << zoneType << " buildings allowed in this zone.\n";
//         return;
//     }

//     // Check if coordinates are within zone boundaries
//     if (x < minX || x > maxX || y < minY || y > maxY) {
//         std::cout << "Error: Coordinates (" << x << ", " << y << ") are outside the zone boundaries.\n";
//         return;
//     }

//     // Set building location and add to zone
//     building->setLocation(x, y);
//     buildings.push_back(building);
//     std::cout << zoneType << " building placed at (" << x << ", " << y << ") within zone.\n";
// }

// void ZoneComposite::remove(CityComponent* component){
// 	buildings.erase(std::remove(buildings.begin(), buildings.end(), component), buildings.end());
// }

ZoneComposite::ZoneComposite(const std::string& type, const Location& topLeft, const Location& bottomRight)
    : zoneType(type) {
    bounds[0] = topLeft;
    bounds[1] = bottomRight;
    std::cout << "Created zone of type: " << type << " from (" 
            << topLeft.x << "," << topLeft.y << ") to ("
            << bottomRight.x << "," << bottomRight.y << ")\n";
}

void ZoneComposite::add(std::shared_ptr<CityComponent> component) {
    buildings.push_back(component);
}

void ZoneComposite::remove(std::shared_ptr<CityComponent> component) {
    auto it = std::find(buildings.begin(), buildings.end(), component);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

void ZoneComposite::displayStatus(){
	std::cout << zoneType << " Zone:\n";
    for (auto& building : buildings) {
        building->displayStatus();
    }
}

std::string ZoneComposite::getBuildingType() const{
	return zoneType;
}

void ZoneComposite::accept(taxCollector* TC){
    if (TC) {
        TC->visit(this);  // Let the visitor handle the iteration
    }
}