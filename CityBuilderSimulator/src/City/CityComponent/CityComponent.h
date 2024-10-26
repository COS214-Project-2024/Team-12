#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

#include <iostream>
#include <string>

class CityComponent{
public:
	virtual void add(CityComponent *component) {}
	virtual void remove(CityComponent *component) {}
	virtual void displayStatus() = 0;
	virtual double getTaxRevenue() = 0;
	virtual ~CityComponent() {}
};
#endif