#ifndef ZONE_COMPOSITE_H
#define ZONE_COMPOSITE_H

#include "CityComponent.h"
#include "Location.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class ZoneComposite : public CityComponent{
	private:
	//std::vector<CityComponent*> buildings;
	std::vector<std::shared_ptr<CityComponent>> buildings;
	std::string zoneType;
	Location bounds[2];		//  bounds[0] = top-left, bounds[1] = bottom-right
	//taxCollector* sars;

	//int minX, maxX, minY, maxY;  // Zone boundaries

	public:
//	ZoneComposite(const std::string& type, int minX, int maxX, int minY, int maxY);

	ZoneComposite(const std::string& type, const Location& topLeft, const Location& bottomRight);

//	void add(CityComponent* component, int x, int y) override;

	void add(std::shared_ptr<CityComponent> component);

	void remove(std::shared_ptr<CityComponent> component);

	void displayStatus();

	std::string getBuildingType();

	//void accept(taxCollector* TC) override;

	//void payTax();
};

#endif