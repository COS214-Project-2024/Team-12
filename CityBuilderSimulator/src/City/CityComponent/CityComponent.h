#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

#include "../NPCs/UselessNPC/NPCObserver.h"

#include <iostream>
#include <vector>
#include <string>

class CityComponent{
public:
	virtual void add(CityComponent *component) {}
	virtual void remove(CityComponent *component) {}
	virtual void displayStatus() = 0;
	virtual double getTaxRevenue() = 0;
	virtual ~CityComponent() {}
	void addNpc(NPCObserver* npcs);
	void removeNpc(NPCObserver* npcs);
	void notify();

private:
    std::vector<NPCObserver*> observers;  // List of observers (e.g., NPCObserver)
};
#endif