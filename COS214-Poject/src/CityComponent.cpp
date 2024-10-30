#include "NPCObserver.h"
#include "CityComponent.h"
#include "NPCManager.h"
#include "Government.h"
#include "ReactingNPCS.h"

void CityComponent::addNpc()
{
    int populationGrowth = Government::getInstance().getPopulationGrowth();
    ReactingNPCS prototypeNPC;  // Create a single prototype NPC
    for (int i = 0; i < populationGrowth; i++)
    {
        NPCObserver *newNPC = prototypeNPC.clone();  // Clone the prototype
        observers.push_back(newNPC);                 // Add to NPC collection
    }
}

void CityComponent::removeNpc()
{
    int population = Government::getInstance().getPopulation();
    int decrease = 0;
    double deathPercentage = 0;

    if (NPCManager::getInstance().getHighestState() == "Crime")
    {
        deathPercentage = 0.01;
    }
    else if (NPCManager::getInstance().getHighestState() == "Revolt")
    {
        deathPercentage = 0.25;
    }
    decrease = static_cast<int>(population * deathPercentage);

    while (decrease && !observers.empty())
    {
        delete observers.front();
        observers.erase(observers.begin());
        Government::getInstance().decreasePopulation(1);  // Decrease by one per removal
        --decrease;
    }
    
    if (observers.empty() && decrease > 0)
    {
        std::cout << "No citizens to remove\n";
    }
}


void CityComponent::notify()
{
	for (auto observer : observers)
	{
		observer->update();
	}
}

CityComponent::~CityComponent()
{
    for (auto observer : observers)
    {
        delete observer;
    }
}

void CityComponent::setLocation(int x,int y){
	location = Location(x, y);
}

Location CityComponent::getLocation() const{
	return location;
}
