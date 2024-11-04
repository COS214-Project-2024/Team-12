#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

class NPCObserver;
class taxCollector;

#include "Location.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class CityComponent{
public:
	virtual void add(std::shared_ptr<CityComponent>) {}
	virtual void remove(std::shared_ptr<CityComponent>) {}
	virtual void displayStatus() = 0;
	virtual ~CityComponent();
	void addNpc();
	void removeNpc();
	void notify();

	virtual std::string getBuildingType() const = 0;
	virtual void accept(taxCollector*) = 0;

	//setting the location
	void setLocation(int x, int y);
	void setLocation(const Location&);
	Location getLocation() const;

private:
    std::vector<NPCObserver*> observers;  // List of observers (e.g., NPCObserver)
	Location location;
};

#endif