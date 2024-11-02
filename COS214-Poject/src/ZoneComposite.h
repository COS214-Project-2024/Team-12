#ifndef ZONE_COMPOSITE_H
#define ZONE_COMPOSITE_H

#include "CityComponent.h"
#include <vector>
#include <string>

class ZoneComposite : public CityComponent{
	private:
	std::vector<std::shared_ptr<CityComponent>> buildings;
	std::string zoneType;
	taxCollector* sars;

	int minX, maxX, minY, maxY;  // Zone boundaries

	public:
	ZoneComposite(const std::string& type, int minX, int maxX, int minY, int maxY);

	void add(std::shared_ptr<CityComponent> component) override;

	void remove(std::shared_ptr<CityComponent> component) override;

	void displayStatus() override;

	std::string getBuildingType() override;

	//void accept(taxCollector* TC) override;

	void payTax();
};

#endif