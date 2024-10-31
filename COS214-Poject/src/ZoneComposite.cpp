#include "ZoneComposite.h"
#include "CityComponent.h"

#include <vector>
#include <string>

ZoneComposite::ZoneComposite(const std::string& type, int minX, int maxX, int minY, int maxY) : zoneType(type), minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}

void ZoneComposite::add(CityComponent* building, int x, int y) {
    // Check that the building type matches the zone type
    if (building->getBuildingType() != zoneType) {
        std::cout << "Error: Only " << zoneType << " buildings allowed in this zone.\n";
        return;
    }

    // Check if coordinates are within zone boundaries
    if (x < minX || x > maxX || y < minY || y > maxY) {
        std::cout << "Error: Coordinates (" << x << ", " << y << ") are outside the zone boundaries.\n";
        return;
    }

    // Set building location and add to zone
    building->setLocation(x, y);
    buildings.push_back(building);
    std::cout << zoneType << " building placed at (" << x << ", " << y << ") within zone.\n";
}

void ZoneComposite::remove(CityComponent* component){
	buildings.erase(std::remove(buildings.begin(), buildings.end(), component), buildings.end());
}

void ZoneComposite::displayStatus(){
	std::cout << zoneType << " Zone:\n";
    for (auto& building : buildings) {
        building->displayStatus();
    }
}

std::string ZoneComposite::getBuildingType(){
	return zoneType + "Zone"; 
}

void ZoneComposite::accept(taxCollector* TC){
	for (auto& building : buildings) {
        building->accept(TC);  // Collect taxes from each building
    }
}

void ZoneComposite::payTax(){
	std::vector<CityComponent*>::iterator it;
    for (it = buildings.begin(); it != buildings.end(); ++it) {
        CityComponent* component = *it;
        component->accept(sars);
    }
}