#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

class NPCObserver;
class taxCollector;

#include <iostream>
#include <vector>
#include <string>

class CityComponent{
public:
	virtual void add(CityComponent *component) {}
	virtual void remove(CityComponent *component) {}
	virtual void displayStatus() = 0;
	virtual ~CityComponent();
	void addNpc();
	void removeNpc();
	void notify();

	virtual std::string getBuildingType() = 0;
	virtual void accept(taxCollector* TC)=0;

private:
    std::vector<NPCObserver*> observers;  // List of observers (e.g., NPCObserver)
};
#endif