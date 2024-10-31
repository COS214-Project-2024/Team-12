#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

class NPCObserver;
class taxCollector;

#include "Location.h"

#include <iostream>
#include <vector>
#include <string>

class CityComponent{
public:
	virtual void add(CityComponent *, int , int) {}
	virtual void remove(CityComponent *) {}
	virtual void displayStatus() = 0;
	virtual ~CityComponent();
	void addNpc();
	void removeNpc();
	void notify();

	virtual std::string getBuildingType() = 0;
	virtual void accept(taxCollector*)=0;

	//setting the location
	void setLocation(int x, int y);
	Location getLocation() const;

private:
    std::vector<NPCObserver*> observers;  // List of observers (e.g., NPCObserver)
	Location location;
};
#endif