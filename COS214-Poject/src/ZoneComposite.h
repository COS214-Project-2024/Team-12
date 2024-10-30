#ifndef ZONE_COMPOSITE_H
#define ZONE_COMPOSITE_H

#include "CityComponent.h"
#include <vector>
#include <string>

class ZoneComposite : public CityComponent{
	private:
	std::vector<CityComponent*> buildings;
	std::string zoneType;

	int minX, maxX, minY, maxY;  // Zone boundaries

	public:
	ZoneComposite(const std::string& type, int minX, int maxX, int minY, int maxY);

	void add(CityComponent* component, int x, int y) override;

	void remove(CityComponent* component) override;

	void displayStatus() override;

	std::string getBuildingType() override;

	void accept(taxCollector* TC) override;
};

#endif